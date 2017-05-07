#ifndef RECIPEFORM_H
#define RECIPEFORM_H

#include <QDialog>
#include <QDataWidgetMapper>

namespace Ui {
class RecipeForm;
}

class RecipeForm : public QDialog
{
    Q_OBJECT

public:
    explicit RecipeForm(QWidget *parent = 0);
    RecipeForm(const QModelIndex& index, QWidget* parent = nullptr);

    ~RecipeForm();

private:
    Ui::RecipeForm *ui;
    QDataWidgetMapper* mapper_;
};

#endif // RECIPEFORM_H
