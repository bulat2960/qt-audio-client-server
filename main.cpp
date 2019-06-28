#include <QApplication>
#include <QMediaPlaylist>

#include "window.h"
#include "socket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window* window = new Window();
    Socket* socket = new Socket("localhost", 1234);

    QObject::connect(window, &Window::sendNameToSocket, socket, &Socket::sendRequest);
    QObject::connect(socket, &Socket::downloaded, window, &Window::putToList);

    window->show();

    return a.exec();
}
