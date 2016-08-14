#pragma once

#include "Employee.h"
#include <QtWidgets>
#include <QVBoxLayout>
#include <QHBoxLayout>

class EmployeeView: public QWidget {
public:
    EmployeeView(QWidget *view);
	void printEmployeeInfoAll(vector<Employee *> model);
    QLineEdit *lastNameEdit, *firstNameEdit, *SSNEdit, *hoursDoneEdit, *salaryEdit, *realizedIncomeEdit, *outcomeClaimEdit;
    QComboBox *payTypeMenu;
    QPushButton *addNewEmployeeButton, *saveButton, *calculateSalaryButton, *deleteButton;
    QTreeWidget *treeWidget;

private:
    QWidget *view, *container;
    QHBoxLayout *mainLayout;
    QVBoxLayout *rightLayout;
    QScrollArea *scrollArea;
    QGridLayout *employeeInformationForm;
    void initialize();
    void createTreeWidget(QHBoxLayout *mainLayout);
    void createEemployeeInformationView(QHBoxLayout *mainLayout);
};
