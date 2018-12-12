#include "upgradeclass.h"
#include <QMainWindow>

using namespace std;

UpgradeClass::UpgradeClass(std::string name, double mod, bool a, QPushButton* b){
    purchased = false;
    type = name;
    modifier = mod;
    available = a;
    button = b;
    b->setVisible(a);
}

UpgradeClass::~UpgradeClass(){

}

void UpgradeClass::bought(){
    purchased = true;
}

bool UpgradeClass::isAvailable(){
    return available;
}

bool UpgradeClass::isPurchased(){
    return purchased;
}

void UpgradeClass::setAvailability(){
    if(!available){
        available = true;
        for(auto x : parents){
            if(!x->isAvailable()){
                available = false;
            }
        }
    }
}

double UpgradeClass::getModifier(){
    return modifier;
}

void UpgradeClass::addDescendants(std::vector<UpgradeClass *> p, std::vector<UpgradeClass *> c){
    parents = p;
    children = c;
}

QPushButton* UpgradeClass::getButton(){
    return button;
}
