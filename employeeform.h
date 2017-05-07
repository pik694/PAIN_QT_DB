#ifndef EMPLOYEEFORM_H
#define EMPLOYEEFORM_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDataWidgetMapper>

namespace Ui {
class EmployeeForm;
}

class EmployeeForm : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeForm(QSqlTableModel* model, const QModelIndex& index,  QWidget *parent = 0);
    ~EmployeeForm();

private:
    Ui::EmployeeForm *ui;
    QDataWidgetMapper* mapper;
};

#endif // EMPLOYEEFORM_H
