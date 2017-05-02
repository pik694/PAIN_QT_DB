#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

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
    void primaryTableComboChanged(const QString&);

private:
    QStringList shiftSecondaryComboList, workplaceSecondaryComboList,
            employeeSecondaryComboList, ingredientSecondaryComboList,
            productSecondaryComboList;

};

#endif // MAINWINDOW_H
