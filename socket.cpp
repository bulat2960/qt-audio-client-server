#include "socket.h"

Socket::Socket(QString hostName, quint16 port)
{
    this->connectToHost(hostName, port);
    connect(this, &Socket::readyRead, this, &Socket::readData);
}

void Socket::sendRequest(QString filename)
{
    QByteArray name;
    name.append(filename);
    this->filename = name;
    this->write(name);
    this->waitForBytesWritten();
}

void Socket::readData()
{
    while (this->waitForReadyRead(300) && this->bytesAvailable() > 0)
    {
        audioFile.append(this->readAll());
    }

    QFile file("D:/DevQt/LizaAudioTransfer/AudioTransferClient/audio/" + filename);
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(audioFile);
    }
}
