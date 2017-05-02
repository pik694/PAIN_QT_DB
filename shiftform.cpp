#include "shiftform.h"
#include "ui_shiftform.h"

ShiftForm::ShiftForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShiftForm)
{
    ui->setupUi(this);
}

ShiftForm::~ShiftForm()
{
    delete ui;
}
