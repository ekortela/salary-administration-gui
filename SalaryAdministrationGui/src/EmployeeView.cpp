
#include <QCoreApplication>
#include "EmployeeView.h"


EmployeeView::EmployeeView(QWidget *parent): QMainWindow(parent) {

    m_treeWidgetContainer = new QWidget;
    m_treeWidgetContainer->setWindowTitle("Salary Admin");

    this->m_mainLayout = new QHBoxLayout;
    createEmployeeInformationView(m_mainLayout);
    createTreeWidget(m_mainLayout);

    m_treeWidgetContainer->setLayout(m_mainLayout);
    //window->resize(QDesktopWidget().availableGeometry().size() * 0.3);
    m_treeWidgetContainer->resize(600,350);
    m_treeWidgetContainer->show();
}


void EmployeeView::createTreeWidget(QHBoxLayout *mainLayout)
{
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
    // m_treeWidget->itemDoubleClicked()
     connect(m_treeWidget, SIGNAL (itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT (handleTreeWidgetDoubleClick()) );

    // NOTE: To have the Controller pass the information to the View-object, you need to use
    // the index of the Employee via the IObserver -interface. This will require adding virtual method
    // "handleEventSetActiveEmployee()" to the observer interface and implementing it in the Controller
    // with the required functionality. Remember to call the controller's updateView() -method when
    // model is changed.

    mainLayout->addWidget(m_treeWidget);
}





void EmployeeView::createEmployeeInformationView(QHBoxLayout *mainLayout)
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
    payTypes << ""
             << toString(employee_types::MONTHLY_PAID_EMPLOYEE)
             << toString(employee_types::HOURLY_PAID_EMPLOYEE)
             << toString(employee_types::SALESMAN_EMPLOYEE);
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

    // Buttons / Signals
    m_saveButton = new QPushButton("Save");
    connect(m_saveButton, SIGNAL (released()), this, SLOT (handleSaveButtonClick()) );
    m_deleteButton = new QPushButton("Delete");
    connect(m_deleteButton, SIGNAL (released()), this, SLOT (handleDeleteButtonClick()) );

    // Validators
    //    QIntValidator *intValidator = new QIntValidator(0,999999999,m_hoursDoneEdit);
    //    QDoubleValidator *doubleValidator = new QDoubleValidator(0,999999999,m_hoursDoneEdit);
    //QDoubleValidator *doubleValidator = new QDoubleValidator(0.0,999999999.9,salaryEdit);
    //salaryEdit->setValidator(doubleValidator);
    //realizedIncomeEdit->setValidator(doubleValidator);
    //outcomeClaimEdit->setValidator(doubleValidator);

    // Names
    m_lastNameEdit->setAccessibleName("lastName");
    m_firstNameEdit->setAccessibleName("firstName");
    m_SSNEdit->setAccessibleName("ssn");
    //paytype??
    m_hoursDoneEdit->setAccessibleName("hoursDone");
    m_hourlySalaryEdit->setAccessibleName("salaryEdit");
    m_monthlySalaryEdit->setAccessibleName("realizedIncome");
    m_outcomeClaimCheckBox->setAccessibleName("outcomeClaim");
    m_bonusEdit->setAccessibleName("bonusEdit");

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

    m_leftLayout->addWidget(m_hourlySalaryLabel,5,0);
    m_leftLayout->addWidget(m_hourlySalaryEdit,5,1);

    m_leftLayout->addWidget(m_monthlySalaryLabel,6,0);
    m_leftLayout->addWidget(m_monthlySalaryEdit,6,1);

    m_leftLayout->addWidget(m_outcomeClaimLabel,7,0);
    m_leftLayout->addWidget(m_outcomeClaimCheckBox,7,1);

    m_leftLayout->addWidget(m_bonusLabel,8,0);
    m_leftLayout->addWidget(m_bonusEdit,8,1);

    m_leftLayout->addWidget(m_saveButton,9,0);
    m_leftLayout->addWidget(m_deleteButton,9,1);

    m_displayInfo = new QLabel("info text");
    m_leftLayout->addWidget(m_displayInfo,10,0,1,2);

    m_leftLayout->setColumnStretch(0,1);
    m_scrollAreaContainer->setLayout(m_leftLayout);
    mainLayout->addWidget(m_scrollArea);
}

void EmployeeView::registerObserver(IObserver* observer) {
    this->observer = observer;
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

    if (typ != employee_types::UNKNOWN) {
        observer->handleEventAddEmployee(typ,
                              firstName, lastName, ssn,
                              monthlySalary, hourlySalary, hoursDone, bonus, outcomeClaim);

        QString qstr;

        // TEST m_displayInfo -box
        // TODO REMOVE Get SSN number and set it to display button
        // QString qstr = QString("Type %1 added").arg(QString::number(m_payTypeMenu->currentIndex()) );

        // Display right pane tree widget click item
        //    QString qstr = QString("Item at %1").arg(QString::number(m_mainLayout->itemAt(0)) );

        // m_treeWidget selected row double click item
        // qstr = QString("Current index: %1").arg(QString::number(m_payTypeMenu->currentIndex() ));

        // m_payType ComboBox selected index
        // qstr = QString("Current index: %1").arg(QString::number(m_payTypeMenu->currentIndex() ));

        // m_displayInfo->setText(qstr);
    }
    else {
        popBox("You must select \"Pay Type\"!");
    }
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

void EmployeeView::handleDeleteButtonClick() {
    qDebug() << "Delete button was clicked!";
}

void EmployeeView::popBox(string message) {
    QMessageBox::information(
        this,
        tr( QCoreApplication::applicationName().toStdString().c_str() ),
        tr(message.c_str()) );
}

void EmployeeView::handleTreeWidgetDoubleClick() {
    popBox("Item double clicked!");
}
