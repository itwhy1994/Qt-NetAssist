#include "udp.h"

udp::udp(QObject *parent) : QObject(parent)
{

}

udpserver::udpserver(QHostAddress targetIP, int portNumber)
{
    m_targetIP = targetIP;
    m_iPortNumber = portNumber;
    m_udpSocket = new QUdpSocket(this);
}

bool udpserver::sendData(QString message)
{
    if (message.isEmpty())
    {
        return false;
    }
    int length = 0;
    length = m_udpSocket->writeDatagram(message.toLatin1(), message.length(), m_targetIP, m_iPortNumber);
    if (length != message.length())
    {
        return false;
    }

    return true;
}
