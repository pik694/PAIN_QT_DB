#include "database.h"

Database* Database::instance_ = nullptr;

Database::Database():
    database_(QSqlDatabase::addDatabase("QOCI")),
    employeesTableModel_(nullptr),
    ingredientsTableModel_(nullptr),
    recipesTableModel_(nullptr),
    workplacesTableModel_(nullptr),
    shiftsTableModel_(nullptr),
    empty_(nullptr)
{

    database_.setHostName("ora3.elka.pw.edu.pl");
    database_.setDatabaseName("ora3inf");
    database_.setUserName("pzelazko");
    database_.setPassword("pzelazko");

    if (!database_.open()){
        throw std::runtime_error("Could not connect to the DB");
    }

    database_.exec("alter session set current_schema = pzelazko");
    database_.exec("alter session set nls_date_format = 'dd.mm.yyyy'");
}

Database::~Database(){
    database_.close();
}

QSqlTableModel* Database::getTableModel(const QString& name){

    if (!name.compare("employees", Qt::CaseInsensitive)){
        if (employeesTableModel_ == nullptr){
            employeesTableModel_ = new QSqlTableModel(this, database_);
            employeesTableModel_->setTable(name);

            // TEST
            employeesTableModel_->setEditStrategy(QSqlTableModel::OnFieldChange);
            //employeesTableModel_->setEditStrategy(QSqlTableModel::OnManualSubmit);

            employeesTableModel_->select();
        }
        return employeesTableModel_;
    }
    else if (!name.compare("shifts", Qt::CaseInsensitive)){
        if (shiftsTableModel_ == nullptr){
            shiftsTableModel_ = new QSqlRelationalTableModel(this, database_);
            shiftsTableModel_->setTable(name);
            shiftsTableModel_->setEditStrategy(QSqlTableModel::OnManualSubmit);
            shiftsTableModel_->setRelation(shiftsTableModel_->fieldIndex("workplace_id"), QSqlRelation("workplaces", "workplace_id", "workplace_id"));
            shiftsTableModel_->select();
        }
        return shiftsTableModel_;
    }
    else if (!name.compare("workplaces", Qt::CaseInsensitive)){
        if (workplacesTableModel_ == nullptr){
            workplacesTableModel_= new QSqlRelationalTableModel(this, database_);
            workplacesTableModel_->setTable(name);
            workplacesTableModel_->setEditStrategy(QSqlTableModel::OnManualSubmit);
            workplacesTableModel_->setRelation(workplacesTableModel_->fieldIndex("manager"), QSqlRelation("employees", "pesel", "surname"));
            workplacesTableModel_->select();
        }
        return workplacesTableModel_;
    }
    else if (!name.compare("recipes", Qt::CaseInsensitive)){
        if (recipesTableModel_ == nullptr){
            recipesTableModel_ = new QSqlTableModel(this, database_);
            recipesTableModel_->setTable(name);
            recipesTableModel_->setEditStrategy(QSqlTableModel::OnManualSubmit);
            recipesTableModel_->select();
        }
        return recipesTableModel_;
    }
    else if (!name.compare("ingredients", Qt::CaseInsensitive)){
        if (ingredientsTableModel_ == nullptr){
            ingredientsTableModel_ = new QSqlTableModel(this, database_);
            ingredientsTableModel_->setTable(name);
            ingredientsTableModel_->setEditStrategy(QSqlTableModel::OnManualSubmit);
            ingredientsTableModel_->select();
        }
        return ingredientsTableModel_;
    }
    else if(!name.compare("empty", Qt::CaseInsensitive)){
        if (empty_ == nullptr){
            empty_ = new QSqlTableModel(this, database_);
            empty_->setTable(name);
            empty_->setEditStrategy(QSqlTableModel::OnManualSubmit);
            empty_->select();
        }
        return empty_;
    }
    else {
        QSqlTableModel* model = new QSqlTableModel(this, database_);
        model->setTable(name);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        return model;
    }

}



