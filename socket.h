#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>
#include <QFile>

class Socket : public QTcpSocket
{
    Q_OBJECT
private:
    QByteArray filename;
public:
    Socket(QString hostName, quint16 port);
public slots:
    void sendRequest(QString filename);
    void read();
signals:
    void downloaded(QString name);
};

#endif // SOCKET_H
