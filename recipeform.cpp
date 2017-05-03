#include "recipeform.h"
#include "ui_recipeform.h"

#include <QSlider>
#include <QSpinBox>

RecipeForm::RecipeForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipeForm)
{
    ui->setupUi(this);


   connect(ui->amountSlider, &QSlider::valueChanged,
           ui->amountSpin, &QSpinBox::setValue);

     connect(ui->amountSpin, SIGNAL(valueChanged(int)),
             ui->amountSlider, SLOT(setValue(int)));

}

RecipeForm::~RecipeForm()
{
    delete ui;
}
