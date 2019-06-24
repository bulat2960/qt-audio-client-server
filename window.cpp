#include "window.h"

Window::Window(QString filename, QWidget *parent) : QWidget(parent)
{
    this->filename = filename;

    QPushButton* downloadButton = new QPushButton("Download");
    QPushButton* playButton = new QPushButton("Play");
    QTextEdit* textEdit = new QTextEdit;
    QListWidget* listWidget = new QListWidget;

    QHBoxLayout* controllers = new QHBoxLayout;
    controllers->addWidget(downloadButton);
    controllers->addWidget(playButton);
    controllers->addWidget(textEdit);

    layout = new QVBoxLayout(this);
    layout->addLayout(controllers);
    layout->addWidget(listWidget);

    connect(downloadButton, &QPushButton::clicked, this, &Window::buttonDownloadClicked);
    connect(playButton, &QPushButton::clicked, this, &Window::buttonPlayClicked);
}

void Window::play()
{
    QMediaPlayer *player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile(filename));
    player->setVolume(50);
    player->play();
}
