#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //TODO
    /*
     *Initialize Game State:
     * -Create all upgrade variables
     * -Create cookies and cps variables
     *
    */
    w.show();

    return a.exec();
}
