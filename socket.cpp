#include "socket.h"

Socket::Socket()
{
    connect(this, &Socket::readyRead, this, &Socket::read);

    QDir dir = QDir::current();
    if (!dir.exists("audio"))
    {
        dir.mkdir("audio");
        qDebug() << "Создана директория";
    }
    else
    {
        qDebug() << "Директория audio уже существует";
    }

}

void Socket::connectToServer(QString serverIp)
{
    this->connectToHost(serverIp, 1234);
    if (this->waitForConnected() == false)
    {
        qDebug() << "Подключение по указанному ip не удалось";
    }
    else
    {
        qDebug() << "Соединение с сервером установлено";
    }
}

void Socket::sendRequest(QString filename)
{
    QByteArray name;
    name.append(filename);
    this->filename = name;
    this->write(name);
    this->waitForBytesWritten();
    qDebug() << "Запрос на файл" << name << "послан на сервер";
}

void Socket::read()
{
    QByteArray audioFile;
    while (this->waitForReadyRead(500) && this->bytesAvailable() > 0)
    {
        QByteArray arr = this->readAll();
        if (arr == "File doesn't exist")
        {
            qDebug() << "Такого файла не существует на сервере";
            return;
        }
        audioFile.append(arr);
    }
    qDebug() << "Получаю файл с сервера размером" << audioFile.size() << "байт";

    if (audioFile.size() > 0)
    {
        QString audioNamePath = QDir::currentPath() + "/audio/" + filename;
        QFile file(audioNamePath);
        if (file.open(QIODevice::WriteOnly))
        {
            qDebug() << "Файл создан:" << audioNamePath;
            file.write(audioFile);
        }

        qDebug() << "Файл загружен, отправляю на окно имя файла:" << filename;
        emit downloaded(QString(filename));
    }
}
