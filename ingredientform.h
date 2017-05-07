#ifndef INGREDIENTFORM_H
#define INGREDIENTFORM_H

#include <QDialog>
#include <QDataWidgetMapper>

namespace Ui {
class IngredientForm;
}

class IngredientForm : public QDialog
{
    Q_OBJECT

public:
    explicit IngredientForm(QWidget *parent = nullptr);
    IngredientForm(const QModelIndex& index, QWidget* parent = nullptr);
    ~IngredientForm();

private:
    Ui::IngredientForm *ui;
    QDataWidgetMapper* mapper_;
};

#endif // INGREDIENTFORM_H
