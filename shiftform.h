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
    explicit ShiftForm(QSqlRelationalTableModel* model, QWidget *parent = 0);
    ShiftForm(QSqlRelationalTableModel* model, const QModelIndex& index, QWidget *parent = nullptr);
    ~ShiftForm();

private:
    Ui::ShiftForm *ui;

    QDataWidgetMapper* mapper;
};

#endif // SHIFTFORM_H
