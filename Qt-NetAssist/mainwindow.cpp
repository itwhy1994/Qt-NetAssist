#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString machineName = QHostInfo::localHostName();
    statusBarLabel = new QLabel(machineName);
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
