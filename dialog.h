#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QLineEdit lineEdit;
    QLineEdit lineEdit_2;
    QLineEdit lineEdit_3;
    QLineEdit lineEdit_4;
    QLineEdit lineEdit_5;

private slots:

    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
