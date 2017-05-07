#include "ingredientform.h"
#include "ui_ingredientform.h"

#include <QSqlTableModel>
#include "database.h"

IngredientForm::IngredientForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngredientForm)
{
    ui->setupUi(this);

    QSqlTableModel* model = Database::instance()->getTableModel("ingredients");
    mapper_ = new QDataWidgetMapper(this);

    mapper_->setModel(model);
    mapper_->addMapping(ui->nameFieldBox, model->fieldIndex("name"));
    mapper_->addMapping(ui->priceSpinBox, model->fieldIndex("price_per_kilo"));



}


IngredientForm::IngredientForm(const QModelIndex &index, QWidget *parent):
    IngredientForm(parent)
{
    mapper_->setCurrentIndex(index.row());
}


IngredientForm::~IngredientForm()
{
    delete ui;
}
