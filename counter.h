#ifndef COUNTER_H
#define COUNTER_H
#include <QWidget>
        #include <QString>

        namespace Ui {
        class Form;
        }

        class Form : public QWidget
        {
            Q_OBJECT

        public:
            explicit Form(QWidget *parent = 0);
            ~Form();

        private slots:
            void on_pushButton_clicked();
            int counter=0;

        private:
            Ui::Form *ui;
        };
#endif // COUNTER_H
