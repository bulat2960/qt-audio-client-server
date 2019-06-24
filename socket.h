#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>
#include <QFile>

class Socket : public QTcpSocket
{
private:
    QByteArray audioFile;
    QString filename;
public:
    Socket(quint16 port, QString filename);
public slots:
    void readFile(QByteArray filename);
};

#endif // SOCKET_H
