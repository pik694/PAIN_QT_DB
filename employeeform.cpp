#include "employeeform.h"
#include "ui_employeeform.h"

#include <database.h>

EmployeeForm::EmployeeForm(const QModelIndex& index, QWidget *parent) :
    EmployeeForm(parent)
{
    mapper->setCurrentIndex(index.row());
}

EmployeeForm::EmployeeForm(QWidget *parent):
    QDialog(parent),
    ui(new Ui::EmployeeForm)
{

    ui->setupUi(this);

    QSqlTableModel* model = Database::instance()->getTableModel("employees");
    mapper = new QDataWidgetMapper(this);

    mapper->setModel(model);
    mapper->addMapping(ui->nameField, model->fieldIndex("name"));
    mapper->addMapping(ui->surnameField, model->fieldIndex("surname"));
    mapper->addMapping(ui->PESELField, model->fieldIndex("pesel"));

}



EmployeeForm::~EmployeeForm()
{
    delete ui;
}
