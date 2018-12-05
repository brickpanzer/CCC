#include "clicker.h"
#include "ui_clicker.h"
#include <QString>
#include <cmath>

Clicker::Clicker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clicker)
{
    ui->setupUi(this);

    ui->Display->setReadOnly(true);
    ui->DisplayTitle->setReadOnly(true);
    ui->cpsDisplay->setReadOnly(true);
    ui->cpsTitle->setReadOnly(true);
    ui->Display->setReadOnly(true);

    ui->Clicker1Cost->setReadOnly(true);
    ui->Clicker2Cost->setReadOnly(true);
    ui->Clicker3Cost->setReadOnly(true);
    ui->Clicker4Cost->setReadOnly(true);
    ui->Clicker5Cost->setReadOnly(true);

    ui->Clicker1Count->setReadOnly(true);
    ui->Clicker2Count->setReadOnly(true);
    ui->Clicker3Count->setReadOnly(true);
    ui->Clicker4Count->setReadOnly(true);
    ui->Clicker5Count->setReadOnly(true);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(gameUpdater()));
    timer->start(1000);
}

Clicker::~Clicker()
{
    delete ui;
}

void Clicker::gameUpdater()
{
    count = count + cps;
    ui->Display->setText(QString::number(count,10));
    ui->cpsDisplay->setText(QString::number(cps,10));
}

void Clicker::on_ClickerButton_clicked()
{
    count++;
    ui->Display->setText(QString::number(count,10));
}

void Clicker::on_Clicker1_clicked()
{
    if(count >= CLICKER_1_COST){
        count = count - CLICKER_1_COST;
        CLICKER_1_COST = CLICKER_1_COST * pow(1.15,CLICKER_1_COUNT);
        CLICKER_1_COUNT++;
        cps = cps + 1;
        ui->Display->setText(QString::number(count,10));
        ui->Clicker1Count->setText(QString::number(CLICKER_1_COUNT,10));
        ui->Clicker1Cost->setText(QString::number(CLICKER_1_COST,10));
    }
}

void Clicker::on_Clicker2_clicked()
{
    if(count >= CLICKER_2_COST){
        count = count - CLICKER_2_COST;
        CLICKER_2_COST = CLICKER_2_COST * pow(1.15,CLICKER_2_COUNT);
        CLICKER_2_COUNT++;
        cps = cps + 10;
        ui->Display->setText(QString::number(count,10));
        ui->Clicker2Count->setText(QString::number(CLICKER_2_COUNT,10));
        ui->Clicker2Cost->setText(QString::number(CLICKER_2_COST,10));
    }
}

void Clicker::on_Clicker3_clicked()
{
    if(count >= CLICKER_3_COST){
        count = count - CLICKER_3_COST;
        CLICKER_3_COST = CLICKER_3_COST * pow(1.15,CLICKER_3_COUNT);
        CLICKER_3_COUNT++;
        cps = cps + 30;
        ui->Display->setText(QString::number(count,10));
        ui->Clicker3Count->setText(QString::number(CLICKER_3_COUNT,10));
        ui->Clicker3Cost->setText(QString::number(CLICKER_3_COST,10));
    }
}

void Clicker::on_Clicker4_clicked()
{
    if(count >= CLICKER_4_COST){
        count = count - CLICKER_4_COST;
        CLICKER_4_COST = CLICKER_4_COST * pow(1.15,CLICKER_4_COUNT);
        CLICKER_4_COUNT++;
        cps = cps + 100;
        ui->Display->setText(QString::number(count,10));
        ui->Clicker4Count->setText(QString::number(CLICKER_4_COUNT,10));
        ui->Clicker4Cost->setText(QString::number(CLICKER_4_COST,10));
    }
}

void Clicker::on_Clicker5_clicked()
{
    if(count >= CLICKER_5_COST){
        count = count - CLICKER_5_COST;
        CLICKER_5_COST = CLICKER_5_COST * pow(1.15,CLICKER_5_COUNT);
        CLICKER_5_COUNT++;
        cps = cps + 500;
        ui->Display->setText(QString::number(count,10));
        ui->Clicker5Count->setText(QString::number(CLICKER_5_COUNT,10));
        ui->Clicker5Cost->setText(QString::number(CLICKER_5_COST,10));
    }
}

void Clicker::on_actionReset_triggered()
{
    cps = 0;
    count = 0;

    CLICKER_1_COUNT = 0;
    CLICKER_1_COST = 10;

    CLICKER_2_COUNT = 0;
    CLICKER_2_COST = 100;

    CLICKER_3_COUNT = 0;
    CLICKER_3_COST = 300;

    CLICKER_4_COUNT = 0;
    CLICKER_4_COST = 1000;

    CLICKER_5_COUNT = 0;
    CLICKER_5_COST = 5000;

    ui->Display->setText(QString::number(count,10));
    ui->cpsDisplay->setText(QString::number(cps,10));

    ui->Clicker1Count->setText(QString::number(CLICKER_1_COUNT,10));
    ui->Clicker1Cost->setText(QString::number(CLICKER_1_COST,10));

    ui->Clicker2Count->setText(QString::number(CLICKER_2_COUNT,10));
    ui->Clicker2Cost->setText(QString::number(CLICKER_2_COST,10));

    ui->Clicker3Count->setText(QString::number(CLICKER_3_COUNT,10));
    ui->Clicker3Cost->setText(QString::number(CLICKER_3_COST,10));

    ui->Clicker4Count->setText(QString::number(CLICKER_4_COUNT,10));
    ui->Clicker4Cost->setText(QString::number(CLICKER_4_COST,10));

    ui->Clicker5Count->setText(QString::number(CLICKER_5_COUNT,10));
    ui->Clicker5Cost->setText(QString::number(CLICKER_5_COST,10));
}
