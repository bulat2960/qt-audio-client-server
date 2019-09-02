#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
//#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QListWidget>
#include <QGridLayout>
#include <QDebug>

class Window : public QWidget
{
    Q_OBJECT
private:
    QListWidget* listWidget;
    QTextEdit* audioNameField;
    QTextEdit* serverNameField;

    //QMediaPlayer* player;
    QString currentAudio;

    QVector<QString> filenames;
public:
    explicit Window(QWidget *parent = nullptr);

signals:
    void buttonDownloadClicked();
    void sendAudioNameToSocket(QString name);
    void sendServerIpToSocket(QString name);
public slots:
    void play();
    void pause();
    void getAudioName();
    void getServerIp();
    void putToList(QString name);
};

#endif // WINDOW_H
