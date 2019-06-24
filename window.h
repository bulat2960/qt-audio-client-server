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

class Window : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QString filename;
public:
    explicit Window(QString filename, QWidget *parent = nullptr);

signals:
    void buttonDownloadClicked();
    void buttonPlayClicked();
public slots:
    void play();
};

#endif // WINDOW_H
