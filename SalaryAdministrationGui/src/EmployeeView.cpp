
#include <QCoreApplication>
#include "EmployeeView.h"


EmployeeView::EmployeeView(QWidget *parent): QMainWindow(parent) {

    m_treeWidgetContainer = new QWidget;
    m_treeWidgetContainer->setWindowTitle("Salary Admin");

    this->m_mainLayout = new QHBoxLayout;
    createEemployeeInformationView(m_mainLayout);
    createTreeWidget(m_mainLayout);

    m_treeWidgetContainer->setLayout(m_mainLayout);
    //window->resize(QDesktopWidget().availableGeometry().size() * 0.3);
    m_treeWidgetContainer->resize(600,300);
    m_treeWidgetContainer->show();
}

void EmployeeView::printEmployeeInfoAll(vector<Employee*> model) {
	for (unsigned int i = 0; model.size() > i; i++) {
		model[i]->printInfo();
		cout << "\n";
	}
}


void EmployeeView::createTreeWidget(QHBoxLayout *mainLayout)
{
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

    for (int i = 0; i < 5; i++)
    {
        QTreeWidgetItem *employee = new QTreeWidgetItem(treeWidget);
        employee->setText(0, lastName[i]);
        employee->setText(1, firstName[i]);
        employee->setText(2, payType[i]);
        items.append(employee);
    }
    // muuta leveys

    mainLayout->addWidget(treeWidget);
}

void EmployeeView::createEemployeeInformationView(QHBoxLayout *mainLayout)
{
    m_scrollArea = new QScrollArea;
    m_scrollArea->setWidgetResizable(true);
    m_scrollAreaContainer = new QWidget;
    m_scrollArea->setWidget(m_scrollAreaContainer);
    m_leftLayout = new QGridLayout;

    // Employee information feed
    m_lastNameLabel = new QLabel("Last name:");
    m_lastNameEdit = new QLineEdit();
    m_firstNameLabel = new QLabel("First name(s):");
    m_firstNameEdit = new QLineEdit;
    m_SSNLabel = new QLabel("SSN:");
    m_SSNEdit = new QLineEdit;

    m_payTypeLabel = new QLabel("Pay type:");
    m_payTypeMenu = new QComboBox;

    QStringList payTypes;
    payTypes << "Hourly" << "Monthly" << "Sales";
    m_payTypeMenu->insertItems(0, payTypes);

    m_hoursDoneLabel = new QLabel("Hours done:");
    m_hoursDoneEdit = new QLineEdit;
    m_salaryLabel = new QLabel("Salary:");
    m_salaryEdit = new QLineEdit;
    m_realizedIncomeLabel = new QLabel("Realized income:");
    m_realizedIncomeEdit = new QLineEdit;
    m_outcomeClaimLabel = new QLabel("Outcome claim:");
    m_outcomeClaimEdit = new QLineEdit;

    // Buttons
    m_saveButton = new QPushButton("Save");
    connect(m_saveButton, SIGNAL (released()), this, SLOT (handleSaveButtonClick()) );
    m_deleteButton = new QPushButton("Delete");
    connect(m_deleteButton, SIGNAL (released()), this, SLOT (handleDeleteButtonClick()) );

    // Validators
    QIntValidator *intValidator = new QIntValidator(0,999999999,m_hoursDoneEdit);
    //QDoubleValidator *doubleValidator = new QDoubleValidator(0.0,999999999.9,salaryEdit);
    m_hoursDoneEdit->setValidator(intValidator);
    //salaryEdit->setValidator(doubleValidator);
    //realizedIncomeEdit->setValidator(doubleValidator);
    //outcomeClaimEdit->setValidator(doubleValidator);

    // Names
    m_lastNameEdit->setAccessibleName("lastName");
    m_firstNameEdit->setAccessibleName("firstName");
    m_SSNEdit->setAccessibleName("ssn");
    //paytype??
    m_hoursDoneEdit->setAccessibleName("hoursDone");
    m_salaryEdit->setAccessibleName("salaryEdit");
    m_realizedIncomeEdit->setAccessibleName("realizedIncome");
    m_outcomeClaimEdit->setAccessibleName("outcomeClaim");

    m_leftLayout->addWidget(m_lastNameLabel,0,0);
    m_leftLayout->addWidget(m_lastNameEdit,0,1);
    m_leftLayout->addWidget(m_firstNameLabel,1,0);
    m_leftLayout->addWidget(m_firstNameEdit,1,1);
    m_leftLayout->addWidget(m_SSNLabel,2,0);
    m_leftLayout->addWidget(m_SSNEdit,2,1);
    m_leftLayout->addWidget(m_payTypeLabel,3,0);
    m_leftLayout->addWidget(m_payTypeMenu,3,1);
    m_leftLayout->addWidget(m_hoursDoneLabel,4,0);
    m_leftLayout->addWidget(m_hoursDoneEdit,4,1);
    m_leftLayout->addWidget(m_salaryLabel,5,0);
    m_leftLayout->addWidget(m_salaryEdit,5,1);

    m_leftLayout->addWidget(m_realizedIncomeLabel,6,0);
    m_leftLayout->addWidget(m_realizedIncomeEdit,6,1);
    m_leftLayout->addWidget(m_outcomeClaimLabel,7,0);
    m_leftLayout->addWidget(m_outcomeClaimEdit,7,1);

    m_leftLayout->addWidget(m_saveButton,8,0);
    m_leftLayout->addWidget(m_deleteButton,8,1);

    m_displayInfo = new QLabel("info text");
    m_leftLayout->addWidget(m_displayInfo,9,0,1,2);

    m_leftLayout->setColumnStretch(0,1);
    m_scrollAreaContainer->setLayout(m_leftLayout);
    mainLayout->addWidget(m_scrollArea);
}

void EmployeeView::registerObserver(IObserver* observer) {
    this->observer = observer;
}

void EmployeeView::handleSaveButtonClick() {

    qDebug() << "Save button was clicked!";

    // get SSN number and set it to display button
    QString qstr = this->m_SSNEdit->text();
    m_displayInfo->setText(qstr);

    // TODO AAPO Add arguments for adding new employees
    observer->handleEvent();
}

void EmployeeView::handleDeleteButtonClick() {
    qDebug() << "Delete button was clicked!";
}
