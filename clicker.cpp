#include "clicker.h"
#include "upgradeclass.h"
#include "upgradeclass.cpp"
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

void Clicker::gameBuilder(){

    UpgradeClass *U_1_C_1 = new UpgradeClass("C1-1",1.5,true,ui->c1u1);
    UpgradeClass *U_2_C_1 = new UpgradeClass("C1-2",2.0,false,ui->c1u2);
    UpgradeClass *U_3_C_1 = new UpgradeClass("C1-3",2.0,false,ui->c1u3);
    upgrades.push_back(U_1_C_1);
    upgrades.push_back(U_2_C_1);
    upgrades.push_back(U_3_C_1);

    UpgradeClass *U_1_C_2 = new UpgradeClass("C2-1",1.5,false,ui->c2u1);
    UpgradeClass *U_2_C_2 = new UpgradeClass("C2-2",2.0,false,ui->c2u2);
    UpgradeClass *U_3_C_2 = new UpgradeClass("C2-3",2.0,false,ui->c2u3);
    upgrades.push_back(U_1_C_2);
    upgrades.push_back(U_2_C_2);
    upgrades.push_back(U_3_C_2);

    UpgradeClass *U_1_C_3 = new UpgradeClass("C3-1",1.5,false,ui->c3u1);
    UpgradeClass *U_2_C_3 = new UpgradeClass("C3-2",2.0,false,ui->c3u2);
    UpgradeClass *U_3_C_3 = new UpgradeClass("C3-3",2.0,false,ui->c3u3);
    upgrades.push_back(U_1_C_3);
    upgrades.push_back(U_2_C_3);
    upgrades.push_back(U_3_C_3);

    UpgradeClass *U_1_C_4 = new UpgradeClass("C4-1",1.5,false,ui->c4u1);
    UpgradeClass *U_2_C_4 = new UpgradeClass("C4-2",2.0,false,ui->c4u2);
    UpgradeClass *U_3_C_4 = new UpgradeClass("C4-3",2.0,false,ui->c4u3);
    upgrades.push_back(U_1_C_4);
    upgrades.push_back(U_2_C_4);
    upgrades.push_back(U_3_C_4);

    UpgradeClass *U_1_C_5 = new UpgradeClass("C5-1",1.5,false,ui->c5u1);
    UpgradeClass *U_2_C_5 = new UpgradeClass("C5-2",2.0,false,ui->c5u2);
    UpgradeClass *U_3_C_5 = new UpgradeClass("C5-3",2.0,false,ui->c5u3);
    upgrades.push_back(U_1_C_5);
    upgrades.push_back(U_2_C_5);
    upgrades.push_back(U_3_C_5);

    //PARENTS FIRST, CHILDREN SECOND

    //U1 - 1 parents - 2 children
    //U2 - 2 parents - 2 children
    //U3 - 3 parents - 1 children

    std::vector<UpgradeClass*> parents;
    std::vector<UpgradeClass*> children;
    parents.clear();
    children.clear();

    //C1U1
    //Parents: none
    //Children: C1U2, C2U1
    children.push_back(U_2_C_1);
    children.push_back(U_1_C_2);
    U_1_C_1->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C1U2
    //Parents: C1U1
    //Children: C1U3, C2U2
    parents.push_back(U_1_C_1);
    children.push_back(U_3_C_1);
    children.push_back(U_2_C_2);
    U_2_C_1->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C1U3
    //Parents: C1U2, C2U1
    //Children: C2U3
    parents.push_back(U_2_C_1);
    parents.push_back(U_1_C_2);
    children.push_back(U_3_C_2);
    U_3_C_1->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C2U1
    //Parents: C1U1
    //Children: C3U1, C2U2
    parents.push_back(U_1_C_1);
    children.push_back(U_1_C_3);
    children.push_back(U_2_C_2);
    U_1_C_2->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C2U2
    //Parents: C2U1,C1U2
    //Children: C3U2, C2U3
    parents.push_back(U_1_C_2);
    parents.push_back(U_2_C_1);
    children.push_back(U_3_C_2);
    children.push_back(U_2_C_3);
    U_2_C_2->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C2U3
    //Parents: C1U3,C2U2
    //Children: C3U3
    parents.push_back(U_3_C_1);
    parents.push_back(U_2_C_2);
    children.push_back(U_3_C_3);
    U_3_C_2->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C3U1
    //Parents: C2U1
    //Children: C4U1, C3U2
    parents.push_back(U_1_C_2);
    children.push_back(U_1_C_4);
    children.push_back(U_2_C_3);
    U_1_C_3->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C3U2
    //Parents: C2U2,C3U1
    //Children: C4U2, C3U3
    parents.push_back(U_2_C_2);
    parents.push_back(U_1_C_3);
    children.push_back(U_3_C_3);
    children.push_back(U_2_C_4);
    U_2_C_3->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C3U3
    //Parents: C2U3,C3U2
    //Children: C4U3
    parents.push_back(U_3_C_2);
    parents.push_back(U_2_C_3);
    children.push_back(U_3_C_4);
    U_3_C_3->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C4U1
    //Parents: C3U1
    //Children: C4U2, C5U1
    parents.push_back(U_1_C_3);
    children.push_back(U_1_C_5);
    children.push_back(U_2_C_4);
    U_1_C_4->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C4U2
    //Parents: C4U1,C3U2
    //Children: C5U2, C4U3
    parents.push_back(U_1_C_4);
    parents.push_back(U_2_C_3);
    children.push_back(U_3_C_4);
    children.push_back(U_2_C_5);
    U_2_C_4->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C4U3
    //Parents: C3U3,C4U2
    //Children: C5U3
    parents.push_back(U_3_C_3);
    parents.push_back(U_2_C_4);
    children.push_back(U_3_C_5);
    U_3_C_4->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C5U1
    //Parents: C4U1
    //Children: C5U2
    parents.push_back(U_1_C_4);
    children.push_back(U_2_C_5);
    U_1_C_5->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C5U2
    //Parents: C5U1,C4U2
    //Children: C5U3
    parents.push_back(U_2_C_4);
    parents.push_back(U_1_C_5);
    children.push_back(U_3_C_5);
    U_2_C_5->addDescendants(parents,children);
    parents.clear();
    children.clear();

    //C5U3
    //Parents: C5U2,C4U3
    //Children: none
    parents.push_back(U_2_C_5);
    parents.push_back(U_3_C_4);
    U_3_C_5->addDescendants(parents,children);
    parents.clear();
    children.clear();

}

void Clicker::gameUpdater()
{
    for(auto &it : upgrades){
        if(it->isAvailable() and !it->isPurchased()){
            it->getButton()->show();
        }
        else{
            it->getButton()->hide();
        }
    }
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
        CLICKER_1_COST = round(CLICKER_1_COST * pow(1.15,CLICKER_1_COUNT));
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
        CLICKER_2_COST = round(CLICKER_2_COST * pow(1.15,CLICKER_2_COUNT));
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
        CLICKER_3_COST = round(CLICKER_3_COST * pow(1.15,CLICKER_3_COUNT));
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
        CLICKER_4_COST = round(CLICKER_4_COST * pow(1.15,CLICKER_4_COUNT));
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
        CLICKER_5_COST = round(CLICKER_5_COST * pow(1.15,CLICKER_5_COUNT));
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

    for(auto &x : upgrades){
        x->reset();
    }
    upgrades.at(0)->overideAvailable(true);

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

void Clicker::on_c1u1_clicked()
{
    if(count >= 1000){
        count = count - 1000;
        cps += CLICKER_1_COUNT * this->upgrades.at(0)->getModifier();
        this->upgrades.at(0)->bought();
        ui->c1u1->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c1u2_clicked()
{
    if(count >= 10000){
        count = count - 10000;
        cps += CLICKER_1_COUNT * this->upgrades.at(1)->getModifier();
        this->upgrades.at(1)->bought();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c1u3_clicked()
{
    if(count >= 100000){
        count = count - 100000;
        cps += CLICKER_1_COUNT * this->upgrades.at(2)->getModifier();
        this->upgrades.at(2)->bought();
        ui->c1u3->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c2u1_clicked()
{
    if(count >= 10000){
        count = count - 10000;
        cps += CLICKER_1_COUNT * this->upgrades.at(3)->getModifier();
        this->upgrades.at(3)->bought();
        ui->c2u1->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c2u2_clicked()
{
    if(count >= 100000){
        count = count - 100000;
        cps += CLICKER_1_COUNT * this->upgrades.at(4)->getModifier();
        this->upgrades.at(4)->bought();
        ui->c2u2->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c2u3_clicked()
{
    if(count >= 1000000){
        count = count - 1000000;
        cps += CLICKER_1_COUNT * this->upgrades.at(5)->getModifier();
        this->upgrades.at(5)->bought();
        ui->c2u3->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c3u1_clicked()
{
    if(count >= 30000){
        count = count - 30000;
        cps += CLICKER_1_COUNT * this->upgrades.at(6)->getModifier();
        this->upgrades.at(6)->bought();
        ui->c3u1->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c3u2_clicked()
{
    if(count >= 300000){
        count = count - 300000;
        cps += CLICKER_1_COUNT * this->upgrades.at(7)->getModifier();
        this->upgrades.at(7)->bought();
        ui->c3u2->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c3u3_clicked()
{
    if(count >= 3000000){
        count = count - 3000000;
        cps += CLICKER_1_COUNT * this->upgrades.at(8)->getModifier();
        this->upgrades.at(8)->bought();
        ui->c3u3->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c4u1_clicked()
{
    if(count >= 100000){
        count = count - 100000;
        cps += CLICKER_1_COUNT * this->upgrades.at(9)->getModifier();
        this->upgrades.at(9)->bought();
        ui->c4u1->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c4u2_clicked()
{
    if(count >= 1000000){
        count = count - 1000000;
        cps += CLICKER_1_COUNT * this->upgrades.at(10)->getModifier();
        this->upgrades.at(10)->bought();
        ui->c4u2->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c4u3_clicked()
{
    if(count >= 10000000){
        count = count - 10000000;
        cps += CLICKER_1_COUNT * this->upgrades.at(11)->getModifier();
        this->upgrades.at(11)->bought();
        ui->c4u3->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c5u1_clicked()
{
    if(count >= 500000){
        count = count - 500000;
        cps += CLICKER_1_COUNT * this->upgrades.at(12)->getModifier();
        this->upgrades.at(12)->bought();
        ui->c1u1->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c5u2_clicked()
{
    if(count >= 5000000){
        count = count - 5000000;
        cps += CLICKER_1_COUNT * this->upgrades.at(13)->getModifier();
        this->upgrades.at(13)->bought();
        ui->c1u1->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}

void Clicker::on_c5u3_clicked()
{
    if(count >= 50000000){
        count = count - 50000000;
        cps += CLICKER_1_COUNT * this->upgrades.at(14)->getModifier();
        this->upgrades.at(14)->bought();
        ui->c1u1->hide();
        ui->Display->setText(QString::number(count,10));
        ui->cpsDisplay->setText(QString::number(cps,10));
    }
}
