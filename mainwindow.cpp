#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employeeform.h"
#include "shiftform.h"
#include "recipeform.h"
#include "ingredientform.h"
#include "database.h"
#include "workplaceform.h"

#include <QDebug>
#include <exception>
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->primaryTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->primaryTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->primaryTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QStringListModel* primaryComboModel = new QStringListModel();
    primaryComboModel->setStringList(Database::instance()->getTables());

    ui->primaryTableCombo->setModel(primaryComboModel);


// MARK:  Setting up combo lists

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

    connect (ui->actionRecipie, &QAction::triggered,
             this, &MainWindow::addRecipeActionTriggered);

    connect(ui->actionIngredient, &QAction::triggered,
            this, &MainWindow::addIngredientTriggered);

    connect(ui->primaryTableView, &QTableView::doubleClicked, this, &MainWindow::doubleClickedOnItemPrimaryTable);


    primaryTableComboChanged(ui->primaryTableCombo->currentText());

}

MainWindow::~MainWindow()
{
    delete ui;
    Database::disconnect();
}

//MARK: SLOTS
void MainWindow::addEmployeeActionTriggered(){

   // EmployeeForm employeeForm;
   // employeeForm.exec();
}

void MainWindow::addShiftActionTriggered(){

    ShiftForm shiftForm;
    shiftForm.exec();
}

void MainWindow::addWorkplaceActionTriggered(){
   // WorkplaceForm workplaceForm;
    //workplaceForm.exec();
}

void MainWindow::addRecipeActionTriggered(){
    RecipeForm recipeForm;
    recipeForm.exec();
}

void MainWindow::addIngredientTriggered(){
    IngredientForm ingredientForm;
    ingredientForm.exec();
}

void MainWindow::primaryTableComboChanged(const QString& text){

    Database::instance()->getPrimaryTable(ui->primaryTableView, text);

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
    ui->secondaryTableCombo->setDisabled(true);
}

void MainWindow::doubleClickedOnItemPrimaryTable(const QModelIndex &index){

    QString text = ui->primaryTableCombo->currentText();



    if (text == "Shifts"){
    }
    else if (text == "Employees"){
        EmployeeForm employeeForm (dynamic_cast<QSqlTableModel*>(ui->primaryTableView->model()), index);
        employeeForm.exec();
    }
    else if(text == "Recipes"){

    }
    else if (text == "Ingredients"){

    }
    else if (text == "Workplaces"){
        WorkplaceForm workplaceForm (dynamic_cast<QSqlRelationalTableModel*> (ui->primaryTableView->model()), index);
        workplaceForm.exec();
    }
    else {
        throw std::out_of_range("Invalid combo item : " + text.toStdString());
    }




}
