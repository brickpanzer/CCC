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
    bool isAvailable();
    void setAvailability();
    double getModifier();
    void addDescendants(std::vector<UpgradeClass*>,std::vector<UpgradeClass*>);
    QPushButton* getButton();
private:
    QPushButton* button;
    std::string type;
    double modifier;
    bool available;
    std::vector<UpgradeClass*> parents;
    std::vector<UpgradeClass*> children;
};

#endif // UPGRADECLASS_H
