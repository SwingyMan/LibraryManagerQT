#include "remover.h"
#include "ui_remover.h"

remover::remover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remover)
{
    ui->setupUi(this);
}

remover::~remover()
{
    delete ui;
}
