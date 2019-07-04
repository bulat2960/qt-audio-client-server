#include <QApplication>
#include <QMediaPlaylist>

#include "window.h"
#include "socket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window* window = new Window();
    Socket* socket = new Socket();

    QObject::connect(window, &Window::sendAudioNameToSocket, socket, &Socket::sendRequest);
    QObject::connect(window, &Window::sendServerIpToSocket, socket, &Socket::connectToServer);
    QObject::connect(socket, &Socket::downloaded, window, &Window::putToList);

    window->show();

    return a.exec();
}
