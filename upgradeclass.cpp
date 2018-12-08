#include "UpgradeClass.h"
#include <QMainWindow>

using namespace std;

UpgradeClass::UpgradeClass(std::string name, double mod, bool a, QPushButton* b){
    type = name;
    modifier = mod;
    available = a;
    button = b;
}

UpgradeClass::~UpgradeClass(){

}

bool UpgradeClass::isAvailable(){
    return available;
}

void UpgradeClass::setAvailability(){

}

double UpgradeClass::getModifier(){
    return 0.0;
}

void UpgradeClass::addDescendants(std::vector<UpgradeClass *>, std::vector<UpgradeClass *>){

}

QPushButton* UpgradeClass::getButton(){
    return button;
}
