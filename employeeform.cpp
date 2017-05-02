#include "employeeform.h"
#include "ui_employeeform.h"

EmployeeForm::EmployeeForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeForm)
{
    ui->setupUi(this);
}

EmployeeForm::~EmployeeForm()
{
    delete ui;
}
