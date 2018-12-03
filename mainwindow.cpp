#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //TODO
    //add+destroy buttons every time cycle checks.
    //run this in a loop
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUi(){
    for(){

    }
}
