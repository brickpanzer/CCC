#ifndef CLICKER_H
#define CLICKER_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class Clicker;
}

class Clicker : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clicker(QWidget *parent = nullptr);
    ~Clicker();

private slots:
    void gameUpdater();

    void on_ClickerButton_clicked();

    void on_Clicker1_clicked();

    void on_Clicker2_clicked();

    void on_Clicker3_clicked();

    void on_Clicker4_clicked();

    void on_Clicker5_clicked();

    void on_actionReset_triggered();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    int cps = 0;
    int count = 0;

    int CLICKER_1_COUNT = 0;
    int CLICKER_1_COST = 10;

    int CLICKER_2_COUNT = 0;
    int CLICKER_2_COST = 100;

    int CLICKER_3_COUNT = 0;
    int CLICKER_3_COST = 300;

    int CLICKER_4_COUNT = 0;
    int CLICKER_4_COST = 1000;

    int CLICKER_5_COUNT = 0;
    int CLICKER_5_COST = 5000;

    Ui::Clicker *ui;
    QTimer *timer;
};

#endif // CLICKER_H
