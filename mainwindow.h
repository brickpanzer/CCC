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
    void on_pushButton_clicked();

    void on_lcdNumber_overflow();

    void on_lcdNumber_windowIconTextChanged(const QString &iconText);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
