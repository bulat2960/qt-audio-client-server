#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>
#include <QFile>

class Socket : public QTcpSocket
{
private:
    QByteArray filename;
    QByteArray audioFile;
public:
    Socket(QString hostName, quint16 port);
public slots:
    void sendRequest(QString filename);
    void readData();
};

#endif // SOCKET_H
