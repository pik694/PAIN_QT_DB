#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void addEmployeeActionTriggered();
    void addShiftActionTriggered();
    void addWorkplaceActionTriggered();
    void addRecipeActionTriggered();
    void primaryTableComboChanged(const QString&);
    void secondaryTableComboChanged(const QString&);
    void addIngredientTriggered();
    void doubleClickedOnItemPrimaryTable(const QModelIndex& index);
    void clickedPrimaryTable(const QModelIndex&);

private:
    QStringList shiftSecondaryComboList_, workplaceSecondaryComboList_,
            employeeSecondaryComboList_, ingredientSecondaryComboList_,
            productSecondaryComboList_;

    QSqlTableModel emptyModel_;
};

#endif // MAINWINDOW_H
