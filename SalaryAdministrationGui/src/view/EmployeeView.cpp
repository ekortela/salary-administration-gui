
#include <QCoreApplication>
#include "EmployeeView.h"


EmployeeView::EmployeeView(QWidget *parent): QMainWindow(parent) {

    m_layoutContainer = new QWidget;
    m_layoutContainer->setWindowTitle("Salary Admin");

    this->m_mainLayout = new QHBoxLayout;
    createEmployeeInformationView(m_mainLayout);
    createTreeWidget(m_mainLayout);

    m_layoutContainer->setLayout(m_mainLayout);
    //window->resize(QDesktopWidget().availableGeometry().size() * 0.3);
    m_layoutContainer->resize(600,350);
    m_layoutContainer->setFixedSize(m_layoutContainer->size());
    m_layoutContainer->show();
}


void EmployeeView::createTreeWidget(QHBoxLayout *mainLayout)
{
    m_rightLayout = new QVBoxLayout;
    m_treeWidget = new QTreeWidget;
    m_treeWidget->setColumnCount(3);
    m_treeWidget->setSortingEnabled(true);

    QStringList labels;
    labels << "Last name" << "First name" << "SSN";
    m_treeWidget->setHeaderLabels(labels);

    m_treeWidget->resizeColumnToContents(1);
    m_treeWidget->resizeColumnToContents(2);
    m_treeWidget->resizeColumnToContents(3);

    // TODO ELISA Add double click signal to load employee type
     connect(m_treeWidget, SIGNAL (itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT (handleTreeWidgetDoubleClick()) );

    // NOTE: To have the Controller pass the information to the View-object, you need to use
    // the index of the Employee via the IObserver -interface. This will require adding virtual method
    // "handleEventSetActiveEmployee()" to the observer interface and implementing it in the Controller
    // with the required functionality. Remember to call the controller's updateView() -method when
    // model is changed.

    // Add new employee button
    m_addNewEmployeeButton = new QPushButton("Add new employee");

    m_rightLayout->addWidget(m_treeWidget);
    m_rightLayout->addWidget(m_addNewEmployeeButton);
    mainLayout->addLayout(m_rightLayout);
}

void EmployeeView::createEmployeeInformationView(QHBoxLayout *mainLayout)
{
    // Create structure
    m_leftLayout = new QVBoxLayout;
    m_scrollArea = new QScrollArea;
    m_scrollArea->setMinimumHeight(300);
    m_employeeInfoGrid = new QGridLayout;
    m_buttonLayout = new QHBoxLayout;

    QWidget *empty = new QWidget();
    empty->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    m_employeeInfoGrid->addWidget(empty,7,0);

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
    payTypes << ""
             << employeeTypetoString(employee_types::MONTHLY_PAID_EMPLOYEE)
             << employeeTypetoString(employee_types::HOURLY_PAID_EMPLOYEE)
             << employeeTypetoString(employee_types::SALESMAN_EMPLOYEE);
    m_payTypeMenu->insertItems(0, payTypes);

    m_hoursDoneLabel = new QLabel("Hours done:");
    m_hoursDoneEdit = new QLineEdit;
    m_hoursDoneEdit->setValidator(new QDoubleValidator(0,10000,2,m_hoursDoneEdit) );

    m_monthlySalaryLabel = new QLabel("Monthly Salary:");
    m_monthlySalaryEdit = new QLineEdit;
    m_monthlySalaryEdit->setValidator(new QDoubleValidator(0,20000,2,m_monthlySalaryEdit));

    m_hourlySalaryLabel = new QLabel("Hourly Salary:");
    m_hourlySalaryEdit = new QLineEdit;
    m_hourlySalaryEdit->setValidator(new QDoubleValidator(0,1000,2,m_hourlySalaryEdit));

    m_outcomeClaimLabel = new QLabel("Outcome claim:");
    m_outcomeClaimCheckBox = new QCheckBox;

    m_bonusLabel = new QLabel("Bonus:");
    m_bonusEdit = new QLineEdit;

    m_employeeInfoGrid->addWidget(m_lastNameLabel,0,0);
    m_employeeInfoGrid->addWidget(m_lastNameEdit,0,1);

    m_employeeInfoGrid->addWidget(m_firstNameLabel,1,0);
    m_employeeInfoGrid->addWidget(m_firstNameEdit,1,1);

    m_employeeInfoGrid->addWidget(m_SSNLabel,2,0);
    m_employeeInfoGrid->addWidget(m_SSNEdit,2,1);

    m_employeeInfoGrid->addWidget(m_payTypeLabel,3,0);
    m_employeeInfoGrid->addWidget(m_payTypeMenu,3,1);

    // Monthly
    m_employeeInfoGrid->addWidget(m_monthlySalaryLabel,4,0);
    m_employeeInfoGrid->addWidget(m_monthlySalaryEdit,4,1);

    // Hourly
    m_employeeInfoGrid->addWidget(m_hoursDoneLabel,4,0);
    m_employeeInfoGrid->addWidget(m_hoursDoneEdit,4,1);
    m_employeeInfoGrid->addWidget(m_hourlySalaryLabel,5,0);
    m_employeeInfoGrid->addWidget(m_hourlySalaryEdit,5,1);

    // Salesman
    m_employeeInfoGrid->addWidget(m_outcomeClaimLabel,5,0);
    m_employeeInfoGrid->addWidget(m_outcomeClaimCheckBox,5,1);
    m_employeeInfoGrid->addWidget(m_bonusLabel,6,0);
    m_employeeInfoGrid->addWidget(m_bonusEdit,6,1);

    // Hiding widgets
    setInformationFormWidgetVisibility(false,false,false,false,false);

    m_employeeInfoGrid->setColumnStretch(0,1);


    // Buttons / Signals
    m_saveButton = new QPushButton("Save");
    connect(m_saveButton, SIGNAL (released()), this, SLOT (handleSaveButtonClick()) );
    m_deleteButton = new QPushButton("Delete");
    connect(m_deleteButton, SIGNAL (released()), this, SLOT (handleDeleteButtonClick()) );
    connect(m_payTypeMenu, SIGNAL (currentIndexChanged(int)), this, SLOT (handlePayTypeChange()) );

    m_buttonLayout->addWidget(m_saveButton,0);
    m_buttonLayout->addWidget(m_deleteButton,1);

    //m_displayInfo = new QLabel("info text");
    //m_employeeInfoGrid->addWidget(m_displayInfo,10,0,1,2);

    // Set layouts
    m_scrollArea->setLayout(m_employeeInfoGrid);
    m_leftLayout->addWidget(m_scrollArea);
    m_leftLayout->addLayout(m_buttonLayout);
    mainLayout->addLayout(m_leftLayout);
}

void EmployeeView::registerObserver(IObserver* observer) {
    this->observer = observer;
}

void EmployeeView::updateEmployeeList(vector<Employee *> model) {
    employeeList.clear();
    m_treeWidget->clear();
    for (vector<Employee*>::iterator it = model.begin(); it != model.end(); ++it) {
        QTreeWidgetItem *row = new QTreeWidgetItem(m_treeWidget);
        row->setText(0, QString::fromStdString( (*it)->getFirstName() ));
        row->setText(1, QString::fromStdString( (*it)->getLastName() ));
        row->setText(2, QString::fromStdString( (*it)->getSocialSecurityNumber() ));
        employeeList.append(row);
    }
}

void EmployeeView::popInfoBox(string message) {
    qDebug() << "QmessageBox printing message: \"" << QString::fromStdString(message) << "\"";
    QMessageBox::information(
        this,
        tr( QCoreApplication::applicationName().toStdString().c_str() ),
        tr(message.c_str()) );
}

void EmployeeView::popErrorBox(string message) {
    qDebug() << "QmessageBox printing message: \"" << QString::fromStdString(message) << "\"";
    QMessageBox::critical(
        this,
        tr( QCoreApplication::applicationName().toStdString().c_str() ),
        tr(message.c_str()) );
}


void EmployeeView::handleSaveButtonClick() {
    qDebug() << "Save button was clicked!";

    employee_types::type typ = static_cast<employee_types::type>(m_payTypeMenu->currentIndex());
    string firstName = m_firstNameEdit->text().toStdString();
    string lastName = m_lastNameEdit->text().toStdString();
    string ssn = m_SSNEdit->text().toStdString();
    double monthlySalary = m_monthlySalaryEdit->text().toDouble();
    double hourlySalary = m_hourlySalaryEdit->text().toDouble();
    double hoursDone = m_hoursDoneEdit->text().toDouble();
    double bonus = this->m_bonusEdit->text().toDouble();
    bool outcomeClaim = m_outcomeClaimCheckBox->checkState();

    if (typ != employee_types::UNKNOWN)
    {
        observer->handleEventAddEmployee(typ, firstName, lastName, ssn, monthlySalary, hourlySalary, hoursDone, bonus, outcomeClaim);
    }
    else {
        popInfoBox("You must select \"Pay Type\"!");
    }
}

void EmployeeView::handleDeleteButtonClick() {
    qDebug() << "Delete button was clicked!";
    popInfoBox("Delete button clicked!");
}

void EmployeeView::handleTreeWidgetDoubleClick() {
    unsigned int rowIdx = m_treeWidget->currentIndex().row();
    qDebug() << "Item double clicked: " << QString::number(rowIdx);

    Employee *m_emp = observer->handleEventGetEmployee(m_treeWidget->currentItem()->text(2).toStdString());

    m_firstNameEdit->setText(QString::fromStdString(m_emp->getFirstName()));
    m_lastNameEdit->setText(QString::fromStdString(m_emp->getLastName()));
    m_SSNEdit->setText(m_treeWidget->currentItem()->text(2));

    if (m_emp->getType() == employee_types::MONTHLY_PAID_EMPLOYEE)
    {
        m_payTypeMenu->setCurrentIndex(1);
        MonthlyPaidEmployee *m_monthlyEmp = dynamic_cast <MonthlyPaidEmployee*> (m_emp);

        m_monthlySalaryEdit->setText(QString::number(m_monthlyEmp->getSalary()));

    } else if (m_emp->getType() == employee_types::HOURLY_PAID_EMPLOYEE)
    {
        m_payTypeMenu->setCurrentIndex(2);
        HourlyPaidEmployee *m_hourlyEmp = dynamic_cast <HourlyPaidEmployee*> (m_emp);

        m_hoursDoneEdit->setText(QString::number(m_hourlyEmp->getDoneHours()));
        m_hourlySalaryEdit->setText(QString::number(m_hourlyEmp->getHourlySalary()));

    } else
    {
        m_payTypeMenu->setCurrentIndex(3);
        SalesmanEmployee* m_salesEmp = dynamic_cast <SalesmanEmployee*> (m_emp);

        m_monthlySalaryEdit->setText(QString::number(m_salesEmp->getMonthlySalary()));
        m_outcomeClaimCheckBox->setChecked(m_salesEmp->getOutcomeClaim());
        m_bonusEdit->setText(QString::number(m_salesEmp->getBonus()));
    }
}

void EmployeeView::handlePayTypeChange() {
    qDebug() << "Pay type menu active index changed!";

    if (m_payTypeMenu->currentText().toStdString() == employeeTypetoString(employee_types::MONTHLY_PAID_EMPLOYEE)) {
        setInformationFormWidgetVisibility(true,false,false,false,false);

    } else if (m_payTypeMenu->currentText().toStdString() == employeeTypetoString(employee_types::HOURLY_PAID_EMPLOYEE)) {
        setInformationFormWidgetVisibility(false,true,true,false,false);

    } else if (m_payTypeMenu->currentText().toStdString() == employeeTypetoString(employee_types::SALESMAN_EMPLOYEE)) {
        setInformationFormWidgetVisibility(true,false,false,true,true);

    } else {
        setInformationFormWidgetVisibility(false,false,false,false,false);
    }
}



void EmployeeView::setInformationFormWidgetVisibility(bool mSal, bool hDone, bool hSal, bool oClaim, bool bonus) {
    m_monthlySalaryLabel->setVisible(mSal);
    m_monthlySalaryEdit->setVisible(mSal);
    m_hoursDoneLabel->setVisible(hDone);
    m_hoursDoneEdit->setVisible(hDone);
    m_hourlySalaryLabel->setVisible(hSal);
    m_hourlySalaryEdit->setVisible(hSal);
    m_outcomeClaimLabel->setVisible(oClaim);
    m_outcomeClaimCheckBox->setVisible(oClaim);
    m_bonusLabel->setVisible(bonus);
    m_bonusEdit->setVisible(bonus);
}
