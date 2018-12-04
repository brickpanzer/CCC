#include "mainwindow.h"
#include "main.h"
#include <QApplication>

void gameInitializer(){

    std::string c1str = "clicker";
    double c1double = 0.1;
    unsigned long long int c1ull = 20;

    std::string c2str = "super clicker";
    double c2double = 1;
    unsigned long long int c2ull = 100;

    std::string c3str = "mega clicker";
    double c3double = 10;
    unsigned long long int c3ull = 500;

    std::string c4str = "quantum clicker";
    double c4double = 50;
    unsigned long long int c4ull = 2000;

    std::string c5str = "supreme";
    double c5double = 300;
    unsigned long long int c5ull = 10000;

    Clicker basicClicker(c1str,c1double,c1ull);
    Clicker superClicker(c2str,c2double,c2ull);
    Clicker megaClicker(c3str,c3double,c3ull);
    Clicker quantumClicker(c4str,c4double,c4ull);
    Clicker supreme(c5str,c5double,c5ull);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    gameInitializer();
    w.show();
    return a.exec();
}
