#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateUi();

private slots:

    void on_Click_clicked();

private:
    Ui::MainWindow *ui;
    unsigned long long int cookies = 0;
};

#endif // MAINWINDOW_H
