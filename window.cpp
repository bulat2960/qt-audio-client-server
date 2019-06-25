#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    textEdit = new QTextEdit;
    listWidget = new QListWidget;

    QPushButton* downloadButton = new QPushButton("Download");
    QPushButton* playButton = new QPushButton("Play");

    QHBoxLayout* controllers = new QHBoxLayout;
    controllers->addWidget(downloadButton);
    controllers->addWidget(playButton);
    controllers->addWidget(textEdit);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(controllers);
    layout->addWidget(listWidget);

    connect(downloadButton, &QPushButton::clicked, this, &Window::getNameFromTextEdit);
    connect(playButton, &QPushButton::clicked, this, &Window::play);
}

void Window::play()
{
    QMediaPlayer *player = new QMediaPlayer(this);
    QString s = listWidget->item(listWidget->currentRow())->text();

    QString audioPath = "D:/DevQt/LizaAudioTransfer/AudioTransferClient/audio/";

    player->setMedia(QUrl::fromLocalFile(audioPath + s));
    player->setVolume(50);
    player->play();
}

void Window::getNameFromTextEdit()
{
    QString text = this->textEdit->toPlainText();
    listWidget->addItem(text);
    emit sendNameToSocket(text);
}
