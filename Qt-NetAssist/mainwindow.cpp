#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->targetIP->setText(tr("目标IP:"));
    QString machineName = QHostInfo::localHostName();//Computer Name
    QHostInfo hostInfo = QHostInfo::fromName(machineName);
    QString IPs;
    foreach(QHostAddress IP, hostInfo.addresses())
    {
        IPs += IP.toIPv4Address();
    }
    statusBarLabel = new QLabel(machineName + " " + IPs);
    statusBar()->addPermanentWidget(statusBarLabel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Exit_clicked()
{
    exit(0);
}
