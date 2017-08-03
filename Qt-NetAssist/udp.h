#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QUdpSocket>
#include <QString>

class udp : public QObject
{
    Q_OBJECT
public:
    explicit udp(QObject *parent = 0);

signals:

public slots:
};
class udpserver : public udp
{
public:
    udpserver(QHostAddress targetIP, int portNumber);
    bool sendData(QString message);
private:
    QUdpSocket *m_udpSocket;
    QHostAddress m_targetIP;
    int m_iPortNumber;

};
class udpclient : public udp
{

};

#endif // UDP_H
