#ifndef REMOVER_H
#define REMOVER_H

#include <QDialog>

namespace Ui {
class remover;
}

class remover : public QDialog
{
    Q_OBJECT

public:
    explicit remover(QWidget *parent = nullptr);
    ~remover();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::remover *ui;
};

#endif // REMOVER_H
