
#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <cmath>

class Clicker{
public:
    Clicker(std::string,double,unsigned long long int);
    ~Clicker();
    //increases unit count and modifies cost of next unit
    void addUnit();
    //called when an upgrade is purchased, modifies cps per unit
    void applyUpgrade(double);

    int getUnits();
    double getCpsmod();
private:
    std::string type;
    int units;
    double cpsMod;
    unsigned long long int cost;
};

Clicker::Clicker(std::string t,double c,unsigned long long int co){
    type = t;
    cpsMod = c;
    cost = co;
    units = 0;
}

Clicker::~Clicker(){

}

void Clicker::addUnit(){
    units++;
    if(cost > 1,000,000,000,000,000,000){
        cost = cost + ((1/(units+1))*exp(units)+1);
    }
}

void Clicker::applyUpgrade(double upgrade){
    cpsMod = cpsMod * upgrade;
}

int Clicker::getUnits(){
    return units;
}

double Clicker::getCpsmod(){
    return cpsMod;
}

class Upgrade{
public:
    Upgrade(bool,double,std::vector<Upgrade*>,std::vector<Upgrade*>);
    ~Upgrade();
    void updateAvailable();
    bool isAvailable();
    bool isAdded();
    void addUpgrade(Clicker);
    void wipe();
    std::vector<Upgrade*> getAvailableUpgrades();

private:
    bool added;
    bool available;
    std::vector<Upgrade*> parents;
    std::vector<Upgrade*> children;
    double modifier;
};

Upgrade::Upgrade(bool av,double m,std::vector<Upgrade*> ch,std::vector<Upgrade*> pa){
    added = false;
    available = av;
    modifier = m;
    parents = pa;
    children = ch;
}

Upgrade::~Upgrade(){

}
void Upgrade::addUpgrade(Clicker toBeUpgraded){
    added = true;
    //Update availabilty of children upon addition of upgrade
    /*
     * This ensure updates only occur upon addition of new upgrades
     * Wich allows us to be able to always easily be able to call on an availability check, every frame
     * to display wich upgrades are available without hoggin resources. especially late game
    */
    for(auto x : this->children){
        x->isAvailable();
    }
    toBeUpgraded.applyUpgrade(modifier);
}
void Upgrade::updateAvailable(){
    //if not already available
    if(!this->available){
        //default to available
        this->available = true;
        for(auto x : this->parents){
            //if any parrents is not added, the child cannot be available
            if(!x->added){
                this->available = false;
            }
        }
    }
}
bool Upgrade::isAvailable(){
    return available;
}
bool Upgrade::isAdded(){
    return added;
}
void Upgrade::wipe(){
    added = false;
}

#endif // MAIN_H
