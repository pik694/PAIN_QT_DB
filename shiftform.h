#ifndef SHIFTFORM_H
#define SHIFTFORM_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>

namespace Ui {
class ShiftForm;
}

class ShiftForm : public QDialog
{
    Q_OBJECT

public:
    explicit ShiftForm(QWidget *parent = nullptr);
    ShiftForm(const QModelIndex& index, QWidget* parent = nullptr);
    ~ShiftForm();

private:
    Ui::ShiftForm *ui;

    QDataWidgetMapper* mapper_;
};

#endif // SHIFTFORM_H
