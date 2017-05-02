#ifndef EMPLOYEEFORM_H
#define EMPLOYEEFORM_H

#include <QDialog>

namespace Ui {
class EmployeeForm;
}

class EmployeeForm : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeForm(QWidget *parent = 0);
    ~EmployeeForm();

private:
    Ui::EmployeeForm *ui;
};

#endif // EMPLOYEEFORM_H
