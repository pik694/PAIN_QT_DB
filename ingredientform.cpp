#include "ingredientform.h"
#include "ui_ingredientform.h"

IngredientForm::IngredientForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngredientForm)
{
    ui->setupUi(this);
}

IngredientForm::~IngredientForm()
{
    delete ui;
}
