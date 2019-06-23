#include <QApplication>
#include <QMediaPlaylist>

#include "window.h"
#include "socket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString filename = "D:/2.wav";

    Window* window = new Window(filename);
    Socket* socket = new Socket(1234, filename);

    window->show();

    QObject::connect(window, &Window::buttonDownloadClicked, socket, &Socket::readFile);
    QObject::connect(window, &Window::buttonPlayClicked, window, &Window::play);

    return a.exec();
}
