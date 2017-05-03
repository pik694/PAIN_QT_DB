#ifndef INGREDIENTFORM_H
#define INGREDIENTFORM_H

#include <QDialog>

namespace Ui {
class IngredientForm;
}

class IngredientForm : public QDialog
{
    Q_OBJECT

public:
    explicit IngredientForm(QWidget *parent = 0);
    ~IngredientForm();

private:
    Ui::IngredientForm *ui;
};

#endif // INGREDIENTFORM_H
