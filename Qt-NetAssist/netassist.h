#ifndef NETASSIST_H
#define NETASSIST_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QUdpSocket>

class netassist : public QObject
{
    Q_OBJECT
public:
    explicit netassist(QObject *parent = 0);

signals:

public slots:
};

#endif // NETASSIST_H
