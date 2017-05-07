#include "employeeform.h"
#include "ui_employeeform.h"

EmployeeForm::EmployeeForm(QSqlTableModel* model, const QModelIndex& index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeForm)
{
    ui->setupUi(this);

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(ui->nameField, model->fieldIndex("name"));
    mapper->addMapping(ui->surnameField, model->fieldIndex("surname"));
    mapper->addMapping(ui->PESELField, model->fieldIndex("pesel"));

    mapper->setCurrentIndex(index.row());

}

EmployeeForm::~EmployeeForm()
{
    delete ui;
}
