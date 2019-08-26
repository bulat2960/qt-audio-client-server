#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>
#include <QFile>
#include <QDir>

class Socket : public QTcpSocket
{
    Q_OBJECT
private:
    QByteArray filename;
public:
    Socket();
public slots:
    void sendRequest(QString filename);
    void read();
    void connectToServer(QString serverIp);
signals:
    void downloaded(QString name);
};

#endif // SOCKET_H
