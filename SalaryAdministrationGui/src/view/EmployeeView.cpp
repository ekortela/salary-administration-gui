//============================================================================
// Name        : EmployeeView.cpp
// Author      : Aapo Keskimolo, Elisa Kortela
// Description : Declarations for employee view class methods
//============================================================================

#include <QCoreApplication>
#include "EmployeeView.h"


EmployeeView::EmployeeView(QWidget *parent): QMainWindow(parent) {

    m_layoutContainer = new QWidget;
    m_layoutContainer->setWindowTitle(getQStringFromConfig("main_window"));

    m_mainLayout = new QHBoxLayout;
    createMenuBar();
    createEmployeeInformationView();
    createTreeWidget();

    m_layoutContainer->setLayout(m_mainLayout);
    //window->resize(QDesktopWidget().availableGeometry().size() * 0.3);
    m_layoutContainer->resize(600,350);
    m_layoutContainer->setFixedSize(m_layoutContainer->size());
    m_layoutContainer->show();
}

EmployeeView::~EmployeeView() {
}

QString EmployeeView::getQStringFromConfig(string parameterName) {

    m_xmlFile = new QFile(config_filename);

    QString value = "default";

    if (m_xmlFile->open(QIODevice::ReadOnly | QIODevice::Text)) {

        m_xmlReader = new QXmlStreamReader(m_xmlFile);

        while(!m_xmlReader->atEnd() && !m_xmlReader->hasError()) {

            QXmlStreamReader::TokenType token = m_xmlReader->readNext();

            if(token == QXmlStreamReader::StartElement && token != QXmlStreamReader::StartDocument) {

                string tag = m_xmlReader->name().toString().toStdString();

                if( tag.compare(parameterName) == 0) {
                    value = m_xmlReader->readElementText();
                    qDebug() << "Read xml parameter: " + QString::fromStdString(tag) + ": " << value;
                    break;
                }
            }
        }

        if(m_xmlReader->hasError()) {
            popErrorBox("Parse error \"" + config_filename.toStdString() + "\": " +
                        m_xmlReader->errorString().toStdString());
        }

    } else {
        popErrorBox("Could not open: \"" + config_filename.toStdString() + "\"\nMake sure that your Qt build configuration target (Projects->Build Directory) has been set to the directory that has SalaryAdministrationGui.pro -file\n");
        QApplication::quit();
    }

    m_xmlReader->clear();
    m_xmlFile->close();

    return value;
}



void EmployeeView::createMenuBar() {
    m_menuBar = new QMenuBar(this);
    m_mainLayout->setMenuBar(m_menuBar);

    m_fileMenu = new QMenu(getQStringFromConfig("menu_main"));
    m_menuBar->addMenu(m_fileMenu);
    m_fileMenu->addAction(getQStringFromConfig("menu_new"));
    m_fileMenu->addAction(getQStringFromConfig("menu_save"));
    m_fileMenu->addAction(getQStringFromConfig("menu_load"));
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(getQStringFromConfig("menu_help"));
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(getQStringFromConfig("menu_exit"));
}


void EmployeeView::createTreeWidget()
{
    m_rightLayout = new QVBoxLayout;
    m_treeWidget = new QTreeWidget;
    m_treeWidget->setColumnCount(3);
    m_treeWidget->setSortingEnabled(true);

    QStringList labels;
    labels
        << getQStringFromConfig("treewidget1")
        << getQStringFromConfig("treewidget2")
        << getQStringFromConfig("treewidget3");

    m_treeWidget->setHeaderLabels(labels);

    m_treeWidget->resizeColumnToContents(1);
    m_treeWidget->resizeColumnToContents(2);
    m_treeWidget->resizeColumnToContents(3);

    connect(m_treeWidget, SIGNAL (itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT (handleTreeWidgetDoubleClick()) );

    m_addNewEmployeeButton = new QPushButton(getQStringFromConfig("button_add_emp"));
    connect(m_addNewEmployeeButton, SIGNAL (released()), this, SLOT (handleAddNewEmployeeButtonClick()) );

    m_rightLayout->addWidget(m_treeWidget);
    m_rightLayout->addWidget(m_addNewEmployeeButton);
    m_mainLayout->addLayout(m_rightLayout);
}

void EmployeeView::createEmployeeInformationView()
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
    m_lastNameLabel = new QLabel(getQStringFromConfig("editor_lastname"));
    m_lastNameEdit = new QLineEdit();
    m_firstNameLabel = new QLabel(getQStringFromConfig("editor_firstname"));
    m_firstNameEdit = new QLineEdit;
    m_SSNLabel = new QLabel(getQStringFromConfig("editor_ssn"));
    m_SSNEdit = new QLineEdit;

    m_payTypeLabel = new QLabel(getQStringFromConfig("editor_pay_type"));
    m_payTypeMenu = new QComboBox;

    QStringList payTypes;
    payTypes << ""
             << employeeTypetoString(employee_types::MONTHLY_PAID_EMPLOYEE)
             << employeeTypetoString(employee_types::HOURLY_PAID_EMPLOYEE)
             << employeeTypetoString(employee_types::SALESMAN_EMPLOYEE);
    m_payTypeMenu->insertItems(0, payTypes);

    m_hoursDoneLabel = new QLabel(getQStringFromConfig("editor_hours_done"));
    m_hoursDoneEdit = new QLineEdit;
    m_hoursDoneEdit->setValidator(new QDoubleValidator(0,10000,2,m_hoursDoneEdit) );

    m_monthlySalaryLabel = new QLabel(getQStringFromConfig("editor_mon_sal"));
    m_monthlySalaryEdit = new QLineEdit;
    m_monthlySalaryEdit->setValidator(new QDoubleValidator(0,20000,2,m_monthlySalaryEdit));

    m_hourlySalaryLabel = new QLabel(getQStringFromConfig("editor_hour_sal"));
    m_hourlySalaryEdit = new QLineEdit;
    m_hourlySalaryEdit->setValidator(new QDoubleValidator(0,1000,2,m_hourlySalaryEdit));

    m_outcomeClaimLabel = new QLabel(getQStringFromConfig("editor_claim"));
    m_outcomeClaimCheckBox = new QCheckBox;

    m_bonusLabel = new QLabel(getQStringFromConfig("editor_bonus"));
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
    m_saveButton = new QPushButton(getQStringFromConfig("button_save_emp"));
    connect(m_saveButton, SIGNAL (released()), this, SLOT (handleSaveButtonClick()) );
    m_deleteButton = new QPushButton(getQStringFromConfig("button_delete_emp"));
    connect(m_deleteButton, SIGNAL (released()), this, SLOT (handleDeleteButtonClick()) );
    connect(m_payTypeMenu, SIGNAL (currentIndexChanged(int)), this, SLOT (handlePayTypeChange()) );

    m_buttonLayout->addWidget(m_saveButton,0);
    m_buttonLayout->addWidget(m_deleteButton,1);

    m_buttonLayout->setStretch(0,1);
    m_buttonLayout->setStretch(1,1);

    //m_displayInfo = new QLabel("info text");
    //m_employeeInfoGrid->addWidget(m_displayInfo,10,0,1,2);

    // Set layouts
    m_scrollArea->setLayout(m_employeeInfoGrid);
    m_leftLayout->addWidget(m_scrollArea);
    m_leftLayout->addLayout(m_buttonLayout);
    m_mainLayout->addLayout(m_leftLayout);
}

void EmployeeView::registerObserver(IObserver* observer) {
    this->m_observer = observer;
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
        m_observer->handleEventAddEmployee(typ, firstName, lastName, ssn, monthlySalary, hourlySalary, hoursDone, bonus, outcomeClaim);
    }
    else {
        popInfoBox("You must select \"Pay Type\"!");
    }
}

void EmployeeView::handleDeleteButtonClick() {
    qDebug() << "Delete button was clicked!";

    if (m_treeWidget->currentItem() != NULL) {

        if(confirmDeletionMessageBox()) {

            for (int i = 0; i < employeeList.size(); i++) {

                if (employeeList[i]->text(2) == m_treeWidget->currentItem()->text(2)) {
                    employeeList.removeAt(i);
                    qDebug() << "Employee removed from employeeList!";
                    if (m_observer->handleEventRemoveEmployee(m_SSNEdit->text().toStdString())) {
                        popInfoBox("Employee deleted");
                        clearForm();
                        m_observer->handleEventRequestViewUpdate();
                        break;
                    }
                }
            }
        }

    } else {
        popErrorBox("Unable to delete! No employee selected.");
    }
}

void EmployeeView::handleAddNewEmployeeButtonClick() {
    qDebug() << "Add new employee button clicked!";
    clearForm();
    m_payTypeMenu->setCurrentIndex(0);
}

void EmployeeView::clearForm() {
    m_firstNameEdit->clear();
    m_lastNameEdit->clear();
    m_SSNEdit->clear();
    m_monthlySalaryEdit->clear();
    m_hoursDoneEdit->clear();
    m_hourlySalaryEdit->clear();
    m_outcomeClaimCheckBox->setChecked(false);
    m_bonusEdit->clear();
}

bool EmployeeView::confirmDeletionMessageBox() {
    QMessageBox::StandardButton confirm;
      confirm = QMessageBox::question(this, "Employee deletoin", "Are you sure you want to delete the employee?",
                                    QMessageBox::Yes|QMessageBox::Cancel);
      if (confirm == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        return true;
      } else {
        qDebug() << "Yes was *not* clicked";
        return false;
      }
}

void EmployeeView::handleTreeWidgetDoubleClick() {
    unsigned int rowIdx = m_treeWidget->currentIndex().row();
    qDebug() << "Item double clicked: " << QString::number(rowIdx);

    clearForm();

    Employee *m_emp = m_observer->handleEventGetEmployee(m_treeWidget->currentItem()->text(2).toStdString());

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


