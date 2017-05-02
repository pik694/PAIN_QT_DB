#ifndef SHIFTFORM_H
#define SHIFTFORM_H

#include <QDialog>

namespace Ui {
class ShiftForm;
}

class ShiftForm : public QDialog
{
    Q_OBJECT

public:
    explicit ShiftForm(QWidget *parent = 0);
    ~ShiftForm();

private:
    Ui::ShiftForm *ui;
};

#endif // SHIFTFORM_H
