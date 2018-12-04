#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cookies = 0;
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
//    for(){
//
//    }
}

void MainWindow::on_Click_clicked()
{
    cookies++;
    ui->CookieDisplay->setText(QString::number(cookies,10));
    this->updateUi();
}
