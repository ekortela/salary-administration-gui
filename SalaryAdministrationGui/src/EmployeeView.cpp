#include "EmployeeView.h"

EmployeeView::EmployeeView(QWidget *view)
{
    this->view = view;
    initialize();
}

void EmployeeView::initialize()
{
    view->setWindowTitle("Salary Admin");

    this->mainLayout = new QHBoxLayout;
    createEemployeeInformationView(mainLayout);
    createTreeWidget(mainLayout);

    view->setLayout(mainLayout);
    //window->resize(QDesktopWidget().availableGeometry().size() * 0.3);
    view->resize(600,300);

    view->show();
}

void EmployeeView::printEmployeeInfoAll(vector<Employee*> model)
{
    for (unsigned int i = 0; model.size() > i; i++) {
        model[i]->printInfo();
        cout << "\n";
    }
}

void EmployeeView::createTreeWidget(QHBoxLayout *mainLayout)
{
    this->rightLayout = new QVBoxLayout;

    // Employee list tree
    this->treeWidget = new QTreeWidget;
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

    for (int i = 0; i < 5; i++)
    {
        QTreeWidgetItem *employee = new QTreeWidgetItem(treeWidget);
        employee->setText(0, lastName[i]);
        employee->setText(1, firstName[i]);
        employee->setText(2, payType[i]);
        items.append(employee);
    }
    // muuta leveys??

    // "Add new employee" button
    this->addNewEmployeeButton = new QPushButton("Add new employee");

    rightLayout->addWidget(treeWidget);
    rightLayout->addWidget(addNewEmployeeButton);

    mainLayout->addLayout(rightLayout);
}

void EmployeeView::createEemployeeInformationView(QHBoxLayout *mainLayout)
{
    this->scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    this->container = new QWidget;
    scrollArea->setWidget(container);
    this->employeeInformationForm = new QGridLayout;

    // Employee information feed
    QLabel *lastNameLabel = new QLabel("Last name:");
    this->lastNameEdit = new QLineEdit;
    QLabel *firstNameLabel = new QLabel("First name(s):");
    this->firstNameEdit = new QLineEdit;
    QLabel *SSNLabel = new QLabel("SSN:");
    this->SSNEdit = new QLineEdit;

    QLabel *payTypeLabel = new QLabel("Pay type:");
    this->payTypeMenu = new QComboBox;
    QStringList payTypes;
    payTypes << "" << "Hourly" << "Monthly" << "Sales";
    payTypeMenu->insertItems(0, payTypes);

    QLabel *hoursDoneLabel = new QLabel("Hours done:");
    this->hoursDoneEdit = new QLineEdit;
    QLabel *salaryLabel = new QLabel("Salary:");
    this->salaryEdit = new QLineEdit;
    QLabel *realizedIncomeLabel = new QLabel("Realized income:");
    this->realizedIncomeEdit = new QLineEdit;
    QLabel *outcomeClaimLabel = new QLabel("Outcome claim:");
    this->outcomeClaimEdit = new QLineEdit;

    // Buttons
    this->saveButton = new QPushButton("Save");
    this->calculateSalaryButton = new QPushButton("Calculate salary");
    this->deleteButton = new QPushButton("Delete");

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
