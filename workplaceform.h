#ifndef WORKPLACEFORM_H
#define WORKPLACEFORM_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QSqlRelationalDelegate>

namespace Ui {
class WorkplaceForm;
}

class WorkplaceForm : public QDialog
{
    Q_OBJECT

public:
    explicit WorkplaceForm(QSqlRelationalTableModel* model, const QModelIndex& index,  QWidget *parent = 0);
    ~WorkplaceForm();

private:
    Ui::WorkplaceForm *ui;

    QDataWidgetMapper* mapper;
};

#endif // WORKPLACEFORM_H
