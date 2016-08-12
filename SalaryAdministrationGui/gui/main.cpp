#include <QApplication>
#include <QtWidgets>
#include <QtCore>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include "main.h"
#include "EmployeeController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;

    EmployeeController controller = EmployeeController(window);

    window->setWindowTitle("Salary Admin");

    QHBoxLayout *mainLayout = new QHBoxLayout;
    createEemployeeInformationView(mainLayout);
    createTreeWidget(mainLayout);

    window->setLayout(mainLayout);
    //window->resize(QDesktopWidget().availableGeometry().size() * 0.3);
    window->resize(600,300);

    window->show();

    return app.exec();
}

void createTreeWidget(QHBoxLayout *mainLayout) {
    QTreeWidget *treeWidget = new QTreeWidget;
    treeWidget->setColumnCount(3);
    treeWidget->setSortingEnabled(true);

    QStringList labels;
    labels << "Last name" << "First name" << "Pay type";
    treeWidget->setHeaderLabels(labels);

    treeWidget->resizeColumnToContents(1);
    treeWidget->resizeColumnToContents(2);
    treeWidget->resizeColumnToContents(3);

    QList<QString> lastName;
    lastName << "Virtanen" << "Nieminen" << "Korhonen" << "Kantola-Ojarinne" << "Holappa";
    QList<QString> firstName;
    firstName << "Jaana" << "Pekka Hannu" << "Pirjo" << "Erkki" << "Liisa Marjatta";
    QList<QString> payType;
    payType << "Hourly" << "Monthly" << "Sales" << "Hourly" << "Sales";

    QList<QTreeWidgetItem *> items;

    for (int i = 0; i < 5; i++) {
        QTreeWidgetItem *employee = new QTreeWidgetItem(treeWidget);
        employee->setText(0, lastName[i]);
        employee->setText(1, firstName[i]);
        employee->setText(2, payType[i]);
        items.append(employee);
    }
    // muuta leveys

    mainLayout->addWidget(treeWidget);
}

void createEemployeeInformationView(QHBoxLayout *mainLayout) {
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    QWidget *container = new QWidget;
    scrollArea->setWidget(container);
    QGridLayout *employeeInformationForm = new QGridLayout;

    // Employee information feed
    QLabel *lastNameLabel = new QLabel("Last name:");
    QLineEdit *lastNameEdit = new QLineEdit;
    QLabel *firstNameLabel = new QLabel("First name(s):");
    QLineEdit *firstNameEdit = new QLineEdit;
    QLabel *SSNLabel = new QLabel("SSN:");
    QLineEdit *SSNEdit = new QLineEdit;

    QLabel *payTypeLabel = new QLabel("Pay type:");
    QComboBox *payTypeMenu = new QComboBox;
    QStringList payTypes;
    payTypes << "Hourly" << "Monthly" << "Sales";
    payTypeMenu->insertItems(0, payTypes);

    QLabel *hoursDoneLabel = new QLabel("Hours done:");
    QLineEdit *hoursDoneEdit = new QLineEdit;
    QLabel *salaryLabel = new QLabel("Salary:");
    QLineEdit *salaryEdit = new QLineEdit;
    QLabel *realizedIncomeLabel = new QLabel("Realized income:");
    QLineEdit *realizedIncomeEdit = new QLineEdit;
    QLabel *outcomeClaimLabel = new QLabel("Outcome claim:");
    QLineEdit *outcomeClaimEdit = new QLineEdit;

    // Buttons
    QPushButton *saveButton = new QPushButton("Save");
    QPushButton *calculateSalaryButton = new QPushButton("Calculate salary");
    QPushButton *deleteButton = new QPushButton("Delete");

    // Validators
    QIntValidator *intValidator = new QIntValidator(0,999999999,hoursDoneEdit);
    //QDoubleValidator *doubleValidator = new QDoubleValidator(0.0,999999999.9,salaryEdit);
    hoursDoneEdit->setValidator(intValidator);
    //salaryEdit->setValidator(doubleValidator);
    //realizedIncomeEdit->setValidator(doubleValidator);
    //outcomeClaimEdit->setValidator(doubleValidator);

    // Names
    lastNameEdit->setAccessibleName("lastName");
    firstNameEdit->setAccessibleName("firstName");
    SSNEdit->setAccessibleName("ssn");
    //paytype??
    hoursDoneEdit->setAccessibleName("hoursDone");
    salaryEdit->setAccessibleName("salaryEdit");
    realizedIncomeEdit->setAccessibleName("realizedIncome");
    outcomeClaimEdit->setAccessibleName("outcomeClaim");

    employeeInformationForm->addWidget(lastNameLabel,0,0);
    employeeInformationForm->addWidget(lastNameEdit,0,1);
    employeeInformationForm->addWidget(firstNameLabel,1,0);
    employeeInformationForm->addWidget(firstNameEdit,1,1);
    employeeInformationForm->addWidget(SSNLabel,2,0);
    employeeInformationForm->addWidget(SSNEdit,2,1);
    employeeInformationForm->addWidget(payTypeLabel,3,0);
    employeeInformationForm->addWidget(payTypeMenu,3,1);
    employeeInformationForm->addWidget(hoursDoneLabel,4,0);
    employeeInformationForm->addWidget(hoursDoneEdit,4,1);
    employeeInformationForm->addWidget(salaryLabel,5,0);
    employeeInformationForm->addWidget(salaryEdit,5,1);

    employeeInformationForm->addWidget(realizedIncomeLabel,6,0);
    employeeInformationForm->addWidget(realizedIncomeEdit,6,1);
    employeeInformationForm->addWidget(outcomeClaimLabel,7,0);
    employeeInformationForm->addWidget(outcomeClaimEdit,7,1);

    employeeInformationForm->addWidget(saveButton,8,0);
    employeeInformationForm->addWidget(deleteButton,8,1);
    employeeInformationForm->addWidget(calculateSalaryButton,9,0,1,2);

    employeeInformationForm->setColumnStretch(0,1);
    container->setLayout(employeeInformationForm);
    mainLayout->addWidget(scrollArea);
}
