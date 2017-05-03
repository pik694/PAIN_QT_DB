#include "workplaceform.h"
#include "ui_workplaceform.h"

WorkplaceForm::WorkplaceForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkplaceForm)
{
    ui->setupUi(this);
}

WorkplaceForm::~WorkplaceForm()
{
    delete ui;
}
