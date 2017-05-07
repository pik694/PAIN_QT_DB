#include "database.h"

Database* Database::instance_ = nullptr;

Database::Database(): database_(QSqlDatabase::addDatabase("QOCI"))
{

    database_.setHostName("ora3.elka.pw.edu.pl");
    database_.setDatabaseName("ora3inf");
    database_.setUserName("pzelazko");
    database_.setPassword("pzelazko");

    if (!database_.open()){
        throw std::runtime_error("Could not connect to the DB");
    }

    database_.exec("alter session set current_schema = pzelazko");

}

Database::~Database(){
    database_.close();
}


void Database::getPrimaryTable(QTableView* view, const QString &name){

      QSqlRelationalTableModel* model =  new QSqlRelationalTableModel(nullptr, database_);

       model->setTable(name);
       model->setEditStrategy(QSqlTableModel::OnFieldChange);

       if (name == "Workplaces"){
           model->setRelation(model->fieldIndex("manager"), QSqlRelation("employees", "pesel", "surname"));
       }

       model->select();

       view->setModel(model);
       view->resizeColumnsToContents();

}



