#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    serverNameField = new QTextEdit;
    serverNameField->setMaximumSize(1000, 50);
    audioNameField = new QTextEdit;
    audioNameField->setMaximumSize(1000, 50);
    listWidget = new QListWidget;

    player = new QMediaPlayer(this);
    player->setVolume(50);

    QPushButton* downloadButton = new QPushButton("Download");
    QPushButton* playButton = new QPushButton("Play");
    QPushButton* stopButton = new QPushButton("Stop");
    QPushButton* connectButton = new QPushButton("Connect");

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(connectButton);
    buttonsLayout->addWidget(downloadButton);
    buttonsLayout->addWidget(playButton);
    buttonsLayout->addWidget(stopButton);

    QHBoxLayout* textLayout = new QHBoxLayout;
    textLayout->addWidget(serverNameField);
    textLayout->addWidget(audioNameField);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(buttonsLayout);
    layout->addLayout(textLayout);
    layout->addWidget(listWidget);

    connect(downloadButton, &QPushButton::clicked, this, &Window::getAudioName);
    connect(connectButton, &QPushButton::clicked, this, &Window::getServerIp);
    connect(playButton, &QPushButton::clicked, this, &Window::play);
    connect(stopButton, &QPushButton::clicked, this, &Window::pause);
}

void Window::play()
{
    QString audioPath = QDir::currentPath() + "/audio/";

    QString s;
    if (listWidget->item(listWidget->currentRow()) != nullptr)
    {
        s = listWidget->item(listWidget->currentRow())->text();

        if (s != currentAudio)
        {
            player->stop();
            player->setMedia(QUrl::fromLocalFile(audioPath + s));
        }
        player->play();

        currentAudio = s;
    }
    else
    {
        qDebug() << "Файл не выбран";
    }
}

void Window::pause()
{
    player->pause();
}

void Window::getAudioName()
{
    QString text = this->audioNameField->toPlainText();
    if (listWidget->findItems(text, Qt::MatchFixedString).empty())
    {
        qDebug() << "Получено имя" << text;
        qDebug() << "Посылаем запрос сокету";
        emit sendAudioNameToSocket(text + ".wav");
    }
    else
    {
        qDebug() << "Такой аудиофайл уже существует";
    }
}

void Window::getServerIp()
{
    QString text = this->serverNameField->toPlainText();
    if (text.size() > 0)
    {
        qDebug() << "Получено имя сервера" << text;
        qDebug() << "Посылаем запрос на подключение к серверу";
        emit sendServerIpToSocket(text);
    }
    else
    {
        qDebug() << "Поле пусто";
    }
}

void Window::putToList(QString name)
{
    if (name == "Error")
    {
        qDebug() << "Такого файла нет на сервере";
    }
    else
    {
        qDebug() << "Название файла добавлено";
        listWidget->addItem(name);
    }
}
