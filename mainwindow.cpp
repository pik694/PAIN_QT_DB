#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employeeform.h"
#include "shiftform.h"
#include <QDebug>
#include <exception>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    shiftSecondaryComboList << "Employees" << "Production";
    workplaceSecondaryComboList << "Employees" << "Shifts";
    employeeSecondaryComboList << "Shifts";
    ingredientSecondaryComboList << "Products";
    productSecondaryComboList << "Shifts" << "Ingredients";

//MARK: Connecting signals to slots

    connect( ui->addEmployeeButton, SIGNAL(triggered()),
            this, SLOT(addEmployeeActionTriggered()));

    connect(ui->addShiftButton, SIGNAL(triggered()),
            this, SLOT(addShiftActionTriggered()));

    connect(ui->addWorkplaceButton, SIGNAL(triggered()),
            this, SLOT(addWorkplaceActionTriggered()));

    connect(ui->primaryTableCombo,
            static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::primaryTableComboChanged);


    primaryTableComboChanged(ui->primaryTableCombo->currentText());

}

MainWindow::~MainWindow()
{
    delete ui;
}

//MARK: SLOTS
void MainWindow::addEmployeeActionTriggered(){

    EmployeeForm employeeForm;
    employeeForm.exec();
}

void MainWindow::addShiftActionTriggered(){

    ShiftForm shiftForm;
    shiftForm.exec();
}

void MainWindow::addWorkplaceActionTriggered(){
    throw std::runtime_error("Not implemented yet");
}

void MainWindow::primaryTableComboChanged(const QString& text){
    //TODO: avoid memory loss
    QStringListModel* secondaryComboModel = new QStringListModel();

    if (text == "Shifts"){
       secondaryComboModel->setStringList(shiftSecondaryComboList);
    }
    else if (text == "Employees"){
       secondaryComboModel->setStringList(employeeSecondaryComboList);

    }
    else if(text == "Recipes"){
        secondaryComboModel->setStringList(productSecondaryComboList);
    }
    else if (text == "Ingredients"){
        secondaryComboModel->setStringList(ingredientSecondaryComboList);
    }
    else if (text == "Workplaces"){
        secondaryComboModel->setStringList(workplaceSecondaryComboList);
    }
    else {
        throw std::out_of_range("Invalid combo item : " + text.toStdString());
    }


    ui->secondaryTableCombo->setModel(secondaryComboModel);
}

