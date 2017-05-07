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

       shiftSecondaryComboList_ << "Employees" << "Production";
       workplaceSecondaryComboList_ << "Employees" << "Shifts";
       employeeSecondaryComboList_ << "Shifts";
       ingredientSecondaryComboList_ << "Products";
       productSecondaryComboList_ << "Shifts" << "Ingredients";

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

    EmployeeForm employeeForm;
    employeeForm.exec();
}

void MainWindow::addShiftActionTriggered(){

    ShiftForm shiftForm;
    shiftForm.exec();
}

void MainWindow::addWorkplaceActionTriggered(){
    WorkplaceForm workplaceForm;
    workplaceForm.exec();
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
    //TODO: fix this method

    ui->primaryTableView->setModel(Database::instance()->getTableModel(text));

    //TODO: avoid memory loss
    QStringListModel* secondaryComboModel = new QStringListModel(this);

    if (text == "Shifts"){
       secondaryComboModel->setStringList(shiftSecondaryComboList_);
    }
    else if (text == "Employees"){
       secondaryComboModel->setStringList(employeeSecondaryComboList_);

    }
    else if(text == "Recipes"){
        secondaryComboModel->setStringList(productSecondaryComboList_);
    }
    else if (text == "Ingredients"){
        secondaryComboModel->setStringList(ingredientSecondaryComboList_);
    }
    else if (text == "Workplaces"){
        secondaryComboModel->setStringList(workplaceSecondaryComboList_);
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
        ShiftForm shiftForm (index);
        shiftForm.exec();
    }
    else if (text == "Employees"){
        EmployeeForm employeeForm (index);
        employeeForm.exec();
    }
    else if(text == "Recipes"){
        RecipeForm recipeForm (index);
        recipeForm.exec();
    }
    else if (text == "Ingredients"){
        IngredientForm ingredientForm (index);
        ingredientForm.exec();
    }
    else if (text == "Workplaces"){
        WorkplaceForm workplaceForm (index);
        workplaceForm.exec();
    }
    else {
        throw std::out_of_range("Invalid combo item : " + text.toStdString());
    }




}
