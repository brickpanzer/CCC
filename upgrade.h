#ifndef UPGRADE_H
#define UPGRADE_H

#include <QMainWindow>

namespace Ui {
class Upgrade;
}

class Upgrade{
public:
    Upgrade(std::string,double,bool);
    ~Upgrade();
    bool isAvailable();
    void setAvailability();
    double getModifier();
    void addDescendants(std::vector<Upgrade*>,std::vector<Upgrade*>);
private:
    std::string type;
    double modifier;
    bool available;
    std::vector<Upgrade*> parents;
    std::vector<Upgrade*> children;
};

#endif // UPGRADE_H
