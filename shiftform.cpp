#include "shiftform.h"
#include "ui_shiftform.h"

ShiftForm::ShiftForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShiftForm)
{
    ui->setupUi(this);

    connect(ui->amountSlider, &QSlider::valueChanged,
            ui->amountSpinBox, &QSpinBox::setValue);
    connect(ui->amountSpinBox, SIGNAL(valueChanged(int)),
            ui->amountSlider, SLOT(setValue(int)));
}

ShiftForm::~ShiftForm()
{
    delete ui;
}
