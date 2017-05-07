#include "workplaceform.h"
#include "ui_workplaceform.h"

#include <database.h>

WorkplaceForm::WorkplaceForm(QWidget *parent):
    QDialog(parent),
    ui(new Ui::WorkplaceForm)
{
    ui->setupUi(this);

    QSqlRelationalTableModel* model = dynamic_cast<QSqlRelationalTableModel*>(Database::instance()->getTableModel("workplaces"));
    QSqlTableModel* relationalModel = model->relationModel(model->fieldIndex("surname"));
    ui->managerComboBox->setModel(relationalModel);
    ui->managerComboBox->setModelColumn(relationalModel->fieldIndex("surname"));

    mapper_ = new QDataWidgetMapper (this);

    mapper_->setModel(model);
    mapper_->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper_->addMapping(ui->managerComboBox, model->fieldIndex("surname"));
    mapper_->addMapping(ui->workplaceNameLineEdit, model->fieldIndex("workplace_id"));

}
WorkplaceForm::WorkplaceForm(const QModelIndex& index,  QWidget *parent):
    WorkplaceForm(parent)
{
        mapper_->setCurrentIndex(index.row());
}


WorkplaceForm::~WorkplaceForm()
{
    delete ui;
}
