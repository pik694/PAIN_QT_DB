#include "shiftform.h"
#include "ui_shiftform.h"

#include <QSqlRelationalDelegate>
#include <database.h>

ShiftForm::ShiftForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShiftForm)
{
    ui->setupUi(this);

    connect(ui->amountSlider, &QSlider::valueChanged,
            ui->amountSpinBox, &QSpinBox::setValue);
    connect(ui->amountSpinBox, SIGNAL(valueChanged(int)),
            ui->amountSlider, SLOT(setValue(int)));



    QSqlRelationalTableModel* model = dynamic_cast<QSqlRelationalTableModel*>(Database::instance()->getTableModel("shifts"));
    mapper = new QDataWidgetMapper(this);

    QSqlTableModel* relationalModel = model->relationModel(model->fieldIndex("workplace_id"));
    ui->workplaceComboBox->setModel(relationalModel);
    ui->workplaceComboBox->setModelColumn(relationalModel->fieldIndex("workplace_id"));

    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(ui->dateEdit, model->fieldIndex("date_of_shift"));
    mapper->addMapping(ui->workplaceComboBox, model->fieldIndex("workplace_id"));


    ui->employeeCombo->setModel(Database::instance()->getTableModel("employees"));
    ui->employeeCombo->setModelColumn(2);
    ui->reciepeCombo->setModel(Database::instance()->getTableModel("recipes"));


}

ShiftForm::ShiftForm(const QModelIndex& index, QWidget* parent):
    ShiftForm(parent)
{
    mapper->setCurrentIndex(index.row());
}

ShiftForm::~ShiftForm()
{
    delete ui;
}
