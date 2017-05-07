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
    explicit EmployeeForm(QWidget *parent = 0);
    EmployeeForm(const QModelIndex& indec, QWidget* parent = nullptr);
    ~EmployeeForm();

private:
    Ui::EmployeeForm *ui;
    QDataWidgetMapper* mapper;
};

#endif // EMPLOYEEFORM_H
