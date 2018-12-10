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
    unsigned int i = 0;
    for(auto x : p){
        parents.at(i) = x;
        i++;
    }
    i = 0;
    for(auto y : c){
        children.at(i) = y;
        i++;
    }
}

QPushButton* UpgradeClass::getButton(){
    return button;
}
