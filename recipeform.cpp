#include "recipeform.h"
#include "ui_recipeform.h"

#include <QSlider>
#include <QSpinBox>
#include <QSqlTableModel>

#include "database.h"


RecipeForm::RecipeForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipeForm)
{
    ui->setupUi(this);


   connect(ui->amountSlider, &QSlider::valueChanged,
           ui->amountSpin, &QSpinBox::setValue);

   connect(ui->amountSpin, SIGNAL(valueChanged(int)),
           ui->amountSlider, SLOT(setValue(int)));


   QSqlTableModel* model = Database::instance()->getTableModel("recipes");
   mapper_ = new QDataWidgetMapper(this);

   mapper_->setModel(model);
   mapper_->addMapping(ui->recipeNameTextField, model->fieldIndex("name"));

   ui->ingredientCombo->setModel(Database::instance()->getTableModel("ingredients"));
}

RecipeForm::RecipeForm(const QModelIndex& index, QWidget* parent):
    RecipeForm(parent)
{
    mapper_->setCurrentIndex(index.row());
}

RecipeForm::~RecipeForm()
{
    delete ui;
}
