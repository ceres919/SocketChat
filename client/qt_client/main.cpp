#include "chatwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatWindow w;
    w.show();
    return a.exec();
}
