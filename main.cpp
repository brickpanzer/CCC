#include "clicker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clicker w;
    w.gameBuilder();
    w.show();

    return a.exec();
}
