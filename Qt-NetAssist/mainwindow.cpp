#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->targetIP->setText(tr("目标IP:"));
    ui->SendDataButton->setText(tr("发送数据"));
    ui->ExitButton->setText(tr("退出程序"));
    QString machineName = QHostInfo::localHostName();//Computer Name
    QHostInfo hostInfo = QHostInfo::fromName(machineName);
    QString IPs;
    foreach(QHostAddress IP, hostInfo.addresses())
    {
        IPs += IP.toString();
    }
    statusBarLabel = new QLabel(machineName + " " + IPs);
    statusBar()->addPermanentWidget(statusBarLabel);

    m_udpserver = new udpserver(QHostAddress(ui->targetIPlineEdit->text()), 8080);
}

MainWindow::~MainWindow()
{
    delete statusBarLabel;
    delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
    exit(0);
}

void MainWindow::on_SendDataButton_clicked()
{
    m_udpserver->sendData(ui->SendDataBrowser->toPlainText());
    ui->SendDataBrowser->clear();
}
