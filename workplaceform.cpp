#include "workplaceform.h"
#include "ui_workplaceform.h"

WorkplaceForm::WorkplaceForm(QSqlRelationalTableModel* model, const QModelIndex& index,  QWidget *parent):
    QDialog(parent),
    ui(new Ui::WorkplaceForm)
{
    ui->setupUi(this);

    ui->managerComboBox->setModel(model);
    ui->managerComboBox->setModelColumn(model->fieldIndex("surname"));

    mapper = new QDataWidgetMapper (this);

    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(ui->managerComboBox, model->fieldIndex("surname"));
    mapper->addMapping(ui->workplaceNameLineEdit, model->fieldIndex("workplace_id"));

    mapper->setCurrentIndex(index.row());


}

WorkplaceForm::~WorkplaceForm()
{
    delete ui;

    mapper->model()->submit();
}
