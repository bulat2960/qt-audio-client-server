#include "socket.h"

Socket::Socket(QString hostName, quint16 port)
{
    this->connectToHost(hostName, port);
    connect(this, &Socket::readyRead, this, &Socket::read);
}

void Socket::sendRequest(QString filename)
{
    QByteArray name;
    name.append(filename);
    this->filename = name;
    this->write(name);
    this->waitForBytesWritten();
    qDebug() << "Запрос на файл" << name << "послан на сервер.";
}

void Socket::read()
{
    QByteArray audioFile;

    while (this->waitForReadyRead(300) && this->bytesAvailable() > 0)
    {
        audioFile.append(this->readAll());
    }

    qDebug() << "Получаю файл с сервера размером" << audioFile.size() << "байт.";

    if (audioFile.size() > 0)
    {
        QFile file("D:/DevQt/LizaAudioTransfer/AudioTransferClient/audio/" + filename);
        if (file.open(QIODevice::WriteOnly))
        {
            file.write(audioFile);
        }

        qDebug() << "Файл загружен, отправляю на окно имя файла:" << filename << ".";
        emit downloaded(QString(filename));
    }
    else
    {
        qDebug() << "Файл пуст, отправляю на окно ошибку.";
        emit downloaded(QString("Error"));
    }
}
