#include <QApplication>
#include <QtWidgets> //pushbuttons, labels, etc.
#include <QtCore> //strings, etc.
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include "main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Salary Admin");

    //RIGHT SIDE

    // - Tree
    QTreeWidget *treeWidget = new QTreeWidget;
    createTreeWidget(treeWidget);


    //LEFT SIDE

    QVBoxLayout *leftLayout = new QVBoxLayout;
    createEemployeeInformationView(leftLayout);


    //FINISH

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addWidget(treeWidget);

    window->setLayout(mainLayout);

    window->setBaseSize(1043, 600);

    window->show();

    return app.exec();
}

void createTreeWidget(QTreeWidget *treeWidget) {
    treeWidget->setColumnCount(3);

    QStringList labels;
    labels << "Last name" << "First name" << "Pay type";
    treeWidget->setHeaderLabels(labels);

    QList<QString> lastName;
    lastName << "Virtanen" << "Nieminen" << "Korhonen" << "Kantola" << "Holappa";
    QList<QString> firstName;
    firstName << "Jaana" << "Pekka" << "Pirjo" << "Erkki" << "Liisa";
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
}

void createEemployeeInformationView(QVBoxLayout *leftLayout) {
    QLineEdit *lastNameEdit = new QLineEdit;
    QLineEdit *firstNameEdit = new QLineEdit;
    QLineEdit *hoursDoneEdit = new QLineEdit;
    QLineEdit *salaryEdit = new QLineEdit;

    QFormLayout *employeeInformationForm = new QFormLayout;
    employeeInformationForm->addRow("Last name", lastNameEdit);
    employeeInformationForm->addRow("First name:", firstNameEdit);
    employeeInformationForm->addRow("Hours done:", hoursDoneEdit);
    employeeInformationForm->addRow("Salary:", salaryEdit);

    //QDialogButtonBox *detailsButtonBox = new QDialogButtonBox;
    //detailsButtonBox->addButton("Save", QDialogButtonBox::InvalidRole);
    //detailsButtonBox->addButton("Calculate salary", QDialogButtonBox::InvalidRole);
    //detailsButtonBox->addButton("Clear", QDialogButtonBox::InvalidRole);

    QHBoxLayout *detailsButtonBox = new QHBoxLayout;
    QPushButton *save = new QPushButton("Save");
    QPushButton *calculateSalary = new QPushButton("Calculate salary");
    QPushButton *clear = new QPushButton("Clear form");
    detailsButtonBox->addWidget(save);
    detailsButtonBox->addWidget(calculateSalary);
    detailsButtonBox->addWidget(clear);

    leftLayout->addLayout(employeeInformationForm);
    leftLayout->addLayout(detailsButtonBox);
}
