#ifndef RECIPEFORM_H
#define RECIPEFORM_H

#include <QDialog>

namespace Ui {
class RecipeForm;
}

class RecipeForm : public QDialog
{
    Q_OBJECT

public:
    explicit RecipeForm(QWidget *parent = 0);
    ~RecipeForm();

private:
    Ui::RecipeForm *ui;
};

#endif // RECIPEFORM_H
