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
    QListWidget* listWidget;
    QTextEdit* textEdit;

    QVector<QString> filenames;
public:
    explicit Window(QWidget *parent = nullptr);

signals:
    void buttonDownloadClicked();
    void sendNameToSocket(QString name);
public slots:
    void play();
    void getNameFromTextEdit();
};

#endif // WINDOW_H
