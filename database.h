#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>

#include <QDebug>


class Database : public QObject
{
public:
    static Database* instance(){

        if (instance_ == nullptr){
            instance_ = new Database();
        }

        return instance_;
    }

    static void disconnect(){
        if (instance_ != nullptr){
            delete instance_;
        }
    }


    QStringList getTables(){
        return QStringList({"Shifts", "Recipes", "Ingredients", "Employees", "Workplaces"});
    }

    QSqlQuery exec(QString query){
        return database_.exec(query);
    }

    QSqlTableModel* getTableModel(const QString& name);

    void commit(){
        database_.commit();
    }


private:
    Database();
    Database(const Database&) = delete;
    Database& operator= (const Database&) = delete;
    ~Database();

    static Database* instance_;

// Attributes
    QSqlDatabase database_;

    QSqlTableModel* employeesTableModel_;
    QSqlTableModel* ingredientsTableModel_;
    QSqlTableModel* recipesTableModel_;
    QSqlRelationalTableModel* workplacesTableModel_;
    QSqlRelationalTableModel* shiftsTableModel_;
    QSqlTableModel* empty_;


};

#endif // DATABASE_H
