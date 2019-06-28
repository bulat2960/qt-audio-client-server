#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    textEdit = new QTextEdit;
    listWidget = new QListWidget;

    player = new QMediaPlayer(this);

    QPushButton* downloadButton = new QPushButton("Download");
    QPushButton* playButton = new QPushButton("Play");
    QPushButton* stopButton = new QPushButton("Stop");

    textEdit->setGeometry(stopButton->geometry());

    QGridLayout* controllers = new QGridLayout;
    controllers->addWidget(downloadButton, 0, 0);
    controllers->addWidget(playButton, 0, 1);
    controllers->addWidget(stopButton, 0, 2);
    controllers->addWidget(textEdit, 1, 1);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(controllers);
    layout->addWidget(listWidget);

    connect(downloadButton, &QPushButton::clicked, this, &Window::getNameFromTextEdit);
    connect(playButton, &QPushButton::clicked, this, &Window::play);
    connect(stopButton, &QPushButton::clicked, this, &Window::stop);
}

void Window::play()
{
    if (listWidget->item(listWidget->currentRow()) != nullptr)
    {
        QString s = listWidget->item(listWidget->currentRow())->text();

        QString audioPath = "D:/DevQt/LizaAudioTransfer/AudioTransferClient/audio/";

        player->setMedia(QUrl::fromLocalFile(audioPath + s));
        player->setVolume(50);
        player->play();
    }
}

void Window::stop()
{
    player->stop();
}

void Window::getNameFromTextEdit()
{
    QString text = this->textEdit->toPlainText();
    emit sendNameToSocket(text);
}

void Window::putToList(QString name)
{
    listWidget->addItem(name);
}
