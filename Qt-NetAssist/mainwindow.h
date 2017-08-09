#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStatusBar>
#include <QHostInfo>
#include <QUdpSocket>
#include <QString>
#include <QByteArray>
#include <QNetworkDatagram>
#include <QtNetwork>
#include <QTcpSocket>
#include <QTcpServer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initUI();
    void initSocket();


private slots:
    void on_ExitButton_clicked();

    void on_SendDataButton_clicked();

    void on_clearButton_clicked();

    void readData();

    void on_DebugInfoBrowser_textChanged();

    void on_ReceiveDataBrowser_textChanged();

    void on_targetIPlineEdit_textChanged(const QString &arg1);

    void on_PortlineEdit_textChanged(const QString &arg1);

    void on_OpenPortButton_clicked();

    void on_ChoosecomboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QLabel *statusBarLabel;
    QUdpSocket m_udpSocketSend;
    QUdpSocket m_udpSocketRead;

    QTcpSocket m_tcpSocketRead;
    QHostAddress m_targetIP;
    quint16 m_targetPort;
    QString m_qstrSocketType;
};

#endif // MAINWINDOW_H
