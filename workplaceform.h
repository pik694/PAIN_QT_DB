#ifndef WORKPLACEFORM_H
#define WORKPLACEFORM_H

#include <QDialog>

namespace Ui {
class WorkplaceForm;
}

class WorkplaceForm : public QDialog
{
    Q_OBJECT

public:
    explicit WorkplaceForm(QWidget *parent = 0);
    ~WorkplaceForm();

private:
    Ui::WorkplaceForm *ui;
};

#endif // WORKPLACEFORM_H
