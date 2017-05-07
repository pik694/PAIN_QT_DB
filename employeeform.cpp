#include "employeeform.h"
#include "ui_employeeform.h"

#include <database.h>

EmployeeForm::EmployeeForm(const QModelIndex& index, QWidget *parent) :
    EmployeeForm(parent)
{
    mapper_->setCurrentIndex(index.row());
}

EmployeeForm::EmployeeForm(QWidget *parent):
    QDialog(parent),
    ui(new Ui::EmployeeForm)
{

    ui->setupUi(this);

    QSqlTableModel* model = Database::instance()->getTableModel("employees");
    mapper_ = new QDataWidgetMapper(this);

    mapper_->setModel(model);
    mapper_->addMapping(ui->nameField, model->fieldIndex("name"));
    mapper_->addMapping(ui->surnameField, model->fieldIndex("surname"));
    mapper_->addMapping(ui->PESELField, model->fieldIndex("pesel"));

}



EmployeeForm::~EmployeeForm()
{
    delete ui;
}
