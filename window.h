#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include <QHBoxLayout>

class Window : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* layout;
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
