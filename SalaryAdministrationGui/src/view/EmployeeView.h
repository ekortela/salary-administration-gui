#pragma once

#include "Employee.h"
#include "MonthlyPaidEmployee.h"
#include "HourlyPaidEmployee.h"
#include "SalesmanEmployee.h"
#include <QtWidgets>
#include "IObserver.h"

class EmployeeView: public QMainWindow {

    Q_OBJECT

public:
    QLineEdit *m_lastNameEdit, *m_firstNameEdit, *m_SSNEdit, *m_hoursDoneEdit,
                *m_hourlySalaryEdit, *m_monthlySalaryEdit, *m_bonusEdit;
    QList<QTreeWidgetItem *> employeeList;

    explicit EmployeeView(QWidget *parent = 0);

    void registerObserver(IObserver *observer);
    void addToEmployeeList(string firstName, string lastName, string payType);
    void updateEmployeeList(vector<Employee *> model);
    void popBox(string message);

private:
    unsigned int *treeWidgetSelectedItem;
    int rowHeight;
    QLabel *m_lastNameLabel, *m_firstNameLabel, *m_SSNLabel, *m_payTypeLabel,
            *m_monthlySalaryLabel, *m_outcomeClaimLabel, *m_hoursDoneLabel,
            *m_hourlySalaryLabel, *m_displayInfo, *m_bonusLabel;
    QComboBox *m_payTypeMenu;
    QPushButton *m_addNewEmployeeButton, *m_saveButton, *m_deleteButton;
    QCheckBox *m_outcomeClaimCheckBox;
    QWidget *m_layoutContainer;
    QHBoxLayout *m_mainLayout, *m_buttonLayout;
    QVBoxLayout *m_leftLayout, *m_rightLayout;
    QScrollArea *m_scrollArea;
    QGridLayout *m_employeeInfoGrid;
    QTreeWidget *m_treeWidget;

    IObserver *observer;

    void createTreeWidget(QHBoxLayout *m_mainLayout);
    void createEmployeeInformationView(QHBoxLayout *m_mainLayout);

private slots:
    void handleSaveButtonClick();
    void handleDeleteButtonClick();
    void handleTreeWidgetDoubleClick();
    void handlePayTypeChange();
};
