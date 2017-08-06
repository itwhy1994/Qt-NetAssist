#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    initUI();
    initUdpSocket();
}

MainWindow::~MainWindow()
{
    delete statusBarLabel;
    delete ui;
}

void MainWindow::initUI()
{
    ui->setupUi(this);
    ui->targetIPlabel->setText(tr("目标IP:"));
    ui->targetPortlabel->setText(tr("目标端口:"));
    ui->OpenPortButton->setText(tr("打开端口"));
    ui->SendDataButton->setText(tr("发送数据"));
    ui->clearButton->setText(tr("清空数据"));
    ui->ExitButton->setText(tr("退出程序"));
    QString machineName = QHostInfo::localHostName();//Computer Name
    QHostInfo hostInfo = QHostInfo::fromName(machineName);
    QString IPs;
    foreach(QHostAddress IP, hostInfo.addresses())
    {
        IPs += IP.toString();
        IPs += " ";
    }
    statusBarLabel = new QLabel(machineName + " " + IPs);
    statusBar()->addPermanentWidget(statusBarLabel);
}

void MainWindow::initUdpSocket()
{
    //Send


    //Read
    connect(&m_udpSocketRead, SIGNAL(readyRead()), this, SLOT(readData()));
}

void MainWindow::on_ExitButton_clicked()
{
    exit(0);
}

void MainWindow::on_SendDataButton_clicked()
{
    QString qstrSendMessage = ui->SendDataBrowser->toPlainText();
    QByteArray baSendData(qstrSendMessage.toLatin1());
    if (m_udpSocketSend.writeDatagram(baSendData, m_targetIP, m_targetPort) == -1)
    {
        ui->DebugInfoBrowser->insertPlainText(tr("Send Failure\n"));
    }
    else
    {
        ui->DebugInfoBrowser->insertPlainText(tr("Send Successful\n"));
    }
}

void MainWindow::on_clearButton_clicked()
{
    ui->ReceiveDataBrowser->clear();
}

void MainWindow::readData()
{
    while (m_udpSocketRead.hasPendingDatagrams())
    {
        QNetworkDatagram datagram = m_udpSocketRead.receiveDatagram();
        QHostAddress senderIP = datagram.senderAddress();
        int senderPort = datagram.senderPort();
        ui->DebugInfoBrowser->insertPlainText("from:" + senderIP.toString() + ":" + \
                                             QString::number(senderPort) +"\n");
        ui->ReceiveDataBrowser->insertPlainText(datagram.data());
    }
}

void MainWindow::on_DebugInfoBrowser_textChanged()
{
    ui->DebugInfoBrowser->moveCursor(QTextCursor::End);
}

void MainWindow::on_ReceiveDataBrowser_textChanged()
{
    ui->ReceiveDataBrowser->moveCursor(QTextCursor::End);
}

void MainWindow::on_targetIPlineEdit_textChanged(const QString &arg1)
{
    m_targetIP = QHostAddress(arg1);
}


void MainWindow::on_PortlineEdit_textChanged(const QString &arg1)
{
    m_targetPort = arg1.toInt();
}

void MainWindow::on_OpenPortButton_clicked()
{
    m_udpSocketRead.disconnectFromHost();
    if (m_udpSocketRead.bind(m_targetPort))
    {
        ui->DebugInfoBrowser->insertPlainText(tr("Listen Successful\n"));
    }
    else
    {
        ui->DebugInfoBrowser->insertPlainText(tr("Listen Failure\n"));
    }
}
