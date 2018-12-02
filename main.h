
#ifndef MAIN_H
#define MAIN_H

#include <vector>

class Upgrade{
public:
    Upgrade(bool,double,std::vector<Upgrade*>,std::vector<Upgrade*>);
    ~Upgrade();
    bool isAvailable();
    bool isAdded();
    void addUpgrade();
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
void Upgrade::addUpgrade(){
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
    //TODO
    //Apply modifier to CPS
}
bool Upgrade::isAvailable(){
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
    return available;
}
bool Upgrade::isAdded(){
    return added;
}
void Upgrade::wipe(){
    added = false;
}
#endif // MAIN_H
