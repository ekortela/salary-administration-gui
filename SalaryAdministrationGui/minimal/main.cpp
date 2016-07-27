#include <QApplication>
#include <QtWidgets>
#include <QtCore>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include "main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Salary Admin");

    QHBoxLayout *mainLayout = new QHBoxLayout;
    createEemployeeInformationView(mainLayout);
    createTreeWidget(mainLayout);

    window->setLayout(mainLayout);
    //window->resize(QDesktopWidget().availableGeometry().size() * 0.3);
    window->resize(600,250);

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
    QWidget *container = new QWidget(scrollArea);
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

    // Buttons
    QPushButton *saveButton = new QPushButton("Save");
    QPushButton *calculateSalaryButton = new QPushButton("Calculate salary");
    QPushButton *deleteButton = new QPushButton("Delete");

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
    employeeInformationForm->addWidget(saveButton,6,0);
    employeeInformationForm->addWidget(deleteButton,6,1);
    employeeInformationForm->addWidget(calculateSalaryButton,7,0,1,2);

    container->setLayout(employeeInformationForm);
    mainLayout->addWidget(scrollArea);
}
