#ifndef UPGRADECLASS_H
#define UPGRADECLASS_H

#include <QMainWindow>
#include <QPushButton>
using namespace std;

namespace Ui {
class UpgradeClass;
}

class UpgradeClass
{
public:
    UpgradeClass(std::string,double,bool,QPushButton*);
    ~UpgradeClass();
    void bought();
    bool isAvailable();
    bool isPurchased();
    void setAvailability();
    double getModifier();
    void addDescendants(std::vector<UpgradeClass*>,std::vector<UpgradeClass*>);
    QPushButton* getButton();
    void reset();
    void overideAvailable(bool);
    void overidePurchased(bool);
private:
    QPushButton* button;
    std::string type;
    double modifier;
    bool available;
    bool purchased;
    std::vector<UpgradeClass*> parents;
    std::vector<UpgradeClass*> children;
};

#endif // UPGRADECLASS_H
