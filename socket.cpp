#include "socket.h"

Socket::Socket(quint16 port, QString filename)
{
    this->filename = filename;

    this->connectToHost("localhost", port);
    if (this->waitForConnected())
    {
        qDebug() << this->state();
    }
}

void Socket::readFile(QByteArray filename)
{
    this->write(filename);
    this->waitForBytesWritten();

    while (this->waitForReadyRead(300) && this->bytesAvailable() > 0)
    {
        qDebug() << this->bytesAvailable();
        audioFile.append(this->readAll());
    }

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(audioFile);
    }
}
