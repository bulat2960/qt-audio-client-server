#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QListWidget>
#include <QGridLayout>

class Window : public QWidget
{
    Q_OBJECT
private:
    QListWidget* listWidget;
    QTextEdit* textEdit;

    QMediaPlayer* player;
    QString currentAudio;

    QVector<QString> filenames;
public:
    explicit Window(QWidget *parent = nullptr);

signals:
    void buttonDownloadClicked();
    void sendNameToSocket(QString name);
public slots:
    void play();
    void pause();
    void getNameFromTextEdit();
    void putToList(QString name);
};

#endif // WINDOW_H
