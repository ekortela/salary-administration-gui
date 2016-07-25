#include <QApplication>
#include <QtWidgets> //pushbuttons, labels, etc.
#include <QtCore> //strings, etc.
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Salary Admin");

    //RIGHT SIDE
    QVBoxLayout *rightLayout = new QVBoxLayout;

    // - Tree
    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(3);

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

    rightLayout->addWidget(treeWidget);

    // - Description
    QScrollArea *itemDescription = new QScrollArea;
    rightLayout->addWidget(itemDescription);


    //LEFT SIDE

    QLineEdit *lastNameEdit = new QLineEdit;
    QLineEdit *firstNameEdit = new QLineEdit;
    QLineEdit *hoursDoneEdit = new QLineEdit;
    QLineEdit *salaryEdit = new QLineEdit;

    QFormLayout *employeeDetailsForm = new QFormLayout;
    employeeDetailsForm->addRow("Last name", lastNameEdit);
    employeeDetailsForm->addRow("First name:", firstNameEdit);
    employeeDetailsForm->addRow("Hours done:", hoursDoneEdit);
    employeeDetailsForm->addRow("Salary:", salaryEdit);

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

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(employeeDetailsForm);
    leftLayout->addLayout(detailsButtonBox);


    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);


    //FINISH
    window->setLayout(mainLayout);
    window->setBaseSize(800, 600);

    window->show();

    return app.exec();
}
