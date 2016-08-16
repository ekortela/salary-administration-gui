#include <QtTest/QtTest>
#include <QCoreApplication>
#include "../src/EmployeeController.h"
#include "../src/EmployeeView.h"

class EmployeeControllerTest: public QObject
{
    Q_OBJECT
public:
    explicit EmployeeControllerTest(QObject *parent = 0);
private slots:
    void initTestCase();
    void addEmployee();
    void cleanupTestCase();
};

EmployeeControllerTest::EmployeeControllerTest(QObject *parent): QObject(parent)
{
}

void EmployeeControllerTest::initTestCase()
{
}

void EmployeeControllerTest::cleanupTestCase()
{
}

void EmployeeControllerTest::addEmployee()
{
    EmployeeView view;
//    EmployeeController controller = EmployeeController(&view);
////    QVerify(controller.addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", "1", 0.0, 0.0, 0.0, 0.0, false));
////    QCompare(controller.get)
////    controller.addEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", "2", 0.0, 0.0, 0.0, 0.0, false);
////    controller.addEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", "3", 0.0, 0.0, 0.0, 0.0, true);
//    QString str = "HELLO";
//    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN(EmployeeControllerTest)

#include "EmployeeControllerTest.moc"
