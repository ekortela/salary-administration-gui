#if 0
#define QT_NO_DEBUG_OUTPUT
#endif
#include <QtTest/QtTest>
#include <QCoreApplication>
#include <QtCore/QDebug>
#include "../src/EmployeeController.h"
#include "../src/EmployeeView.h"


void noMessageOutput(QtMsgType, const QMessageLogContext&, const QString &) { }


class EmployeeControllerTest: public QObject
{
    Q_OBJECT
public:
    explicit EmployeeControllerTest(QObject *parent = 0);
private:
    EmployeeView *m_view;
    EmployeeController *m_controller;
private slots:
    // initialize test cases
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    // test methods
    void addEmployee();
    void getEmployee();
    void removeEmployee();
    void setGetEmployeeFirstName();
    void setGetEmployeeLastName();
    void setGetEmployeeSsn();
    void setGetEmployeeHourlySalary();
    void setGetEmployeeMonthlySalary();
    void setGetEmployeeBonus();
    void setGetEmployeeOutcomeclaim();
    void setGetEmployeeDoneHours();
};

EmployeeControllerTest::EmployeeControllerTest(QObject *parent): QObject(parent) { }

void EmployeeControllerTest::initTestCase()
{
//    cout << "initTestCase" << "\n";
    m_view = new EmployeeView;
    m_controller = new EmployeeController(&(*m_view));
    qInstallMessageHandler(noMessageOutput);
}

void EmployeeControllerTest::cleanupTestCase()
{
//    cout << "cleanupTestCase" << "\n";
    delete m_view;
    delete m_controller;
}

void EmployeeControllerTest::init()
{
//    cout << "init" << "\n";
    QCOMPARE(unsigned int(0), m_controller->getEmployeeCount());
}

void EmployeeControllerTest::cleanup()
{
//    cout << "cleanup" << "\n";
    m_controller->clearEmployees();
}

void EmployeeControllerTest::addEmployee()
{
    int unsigned n = 3;
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", "1", 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->addEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", "2", 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->addEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", "3", 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(!m_controller->addEmployee(employee_types::UNKNOWN, "", "", "4", 0.0, 0.0, 0.0, 0.0, false));
    QCOMPARE(n , m_controller->getEmployeeCount());
}

void EmployeeControllerTest::removeEmployee()
{
    string ssn = "1";\
    int unsigned n = 0;
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->removeEmployee(ssn));
    QCOMPARE(n, m_controller->getEmployeeCount());
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->removeEmployee(ssn));
    QVERIFY(!m_controller->removeEmployee("ssn_doesnt_exist"));
}

void EmployeeControllerTest::setGetEmployeeFirstName() {
    string ssn = "1";
    string firstName = "new_name";
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeFirstName(ssn, firstName));
    QCOMPARE(firstName, m_controller->getEmployeeFirstName(ssn));
}


void EmployeeControllerTest::setGetEmployeeLastName()  {
    string ssn = "1";
    string lastName = "new_name";
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeLastName(ssn, lastName));
    QCOMPARE(lastName, m_controller->getEmployeeLastName(ssn));
}

void EmployeeControllerTest::setGetEmployeeSsn()  {
    string ssn = "1";
    string newSsn = "123";
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeSsn(ssn, newSsn));
    QCOMPARE(newSsn, m_controller->getEmployeeSsn(newSsn));
}

void EmployeeControllerTest::setGetEmployeeHourlySalary()  {
    string ssn = "1";
    double newHourlySalary = 123.4;
    QVERIFY(m_controller->addEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeHourlySalary(ssn, newHourlySalary));
    QCOMPARE(newHourlySalary, m_controller->getEmployeeHourlySalary(ssn));
}

void EmployeeControllerTest::setGetEmployeeMonthlySalary()  {

    // monthly paid employee
    string ssn1 = "1";
    double newMonthlySalary1 = 1.0;
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeMonthlySalary(ssn1, newMonthlySalary1));
    QCOMPARE(newMonthlySalary1, m_controller->getEmployeeMonthlySalary(ssn1));

    // salesman employee
    string ssn2 = "2";
    double newMonthlySalary2 = 2.0;
    QVERIFY(m_controller->addEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeMonthlySalary(ssn2, newMonthlySalary2));
    QCOMPARE(newMonthlySalary2, m_controller->getEmployeeMonthlySalary(ssn2));

    // try to set monthly salary for hourly paid employee
    string ssn3 = "3";
    double newMonthlySalary3 = 3.0;
    QVERIFY(m_controller->addEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(!m_controller->setEmployeeMonthlySalary(ssn3, newMonthlySalary3));
    QCOMPARE(0.0, m_controller->getEmployeeMonthlySalary(ssn3));
}

void EmployeeControllerTest::setGetEmployeeBonus()  {

    // salesman employee
    string ssn1 = "1";
    double newBonus1= 1.0;
    QVERIFY(m_controller->addEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeBonus(ssn1, newBonus1));
    QCOMPARE(newBonus1, m_controller->getEmployeeBonus(ssn1));

    // try to set monthly salary for hourly paid employee
    string ssn2 = "2";
    double newBonus2 = 2.0;
    QVERIFY(m_controller->addEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(!m_controller->setEmployeeBonus(ssn2, newBonus2 ));
    QCOMPARE(0.0 , m_controller->getEmployeeBonus(ssn2));

    // try to set monthly salary for monthly paid employee
    string ssn3 = "3";
    double newBonus3= 3.0;
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(!m_controller->setEmployeeBonus(ssn3, newBonus3));
    QCOMPARE(0.0, m_controller->getEmployeeBonus(ssn3));
}

void EmployeeControllerTest::setGetEmployeeOutcomeclaim()  {

    // salesman employee
    string ssn1 = "1";
    bool newOutcomeClaim1 = true;
    QVERIFY(m_controller->addEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeOutcomeclaim(ssn1, newOutcomeClaim1 ));
    QCOMPARE(newOutcomeClaim1, m_controller->getEmployeeOutcomeClaim(ssn1));

    // try to set outcome claim for hourly paid employee
    string ssn2 = "2";
    double newOutcomeClaim2 = true;
    QVERIFY(m_controller->addEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(!m_controller->setEmployeeBonus(ssn2, newOutcomeClaim2 ));
    QCOMPARE(false , m_controller->getEmployeeOutcomeClaim(ssn2));

    // try to set outcome claim for monthly paid employee
    string ssn3 = "3";
    double newOutcomeClaim3 = true;
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(!m_controller->setEmployeeBonus(ssn3, newOutcomeClaim3));
    QCOMPARE(false, m_controller->getEmployeeOutcomeClaim(ssn3));
}

void EmployeeControllerTest::setGetEmployeeDoneHours() {

    // hourly paid employee
    string ssn1 = "1";
    double newDoneHours1 = 1.0;
    QVERIFY(m_controller->addEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeDoneHours(ssn1, newDoneHours1 ));
    QCOMPARE(newDoneHours1, m_controller->getEmployeeDoneHours(ssn1));

    // try to set done hours for monthly paid employee
    string ssn2 = "2";
    double newDoneHours2 = 2.0;
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(!m_controller->setEmployeeDoneHours(ssn2, newDoneHours2 ));
    QCOMPARE(0.0 , m_controller->getEmployeeDoneHours(ssn2));

    // try to set done hours for salesman employee
    string ssn3 = "3";
    double newDoneHours3 = 3.0;
    QVERIFY(m_controller->addEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(!m_controller->setEmployeeDoneHours(ssn3, newDoneHours3));
    QCOMPARE(0.0, m_controller->getEmployeeDoneHours(ssn3));
}

void EmployeeControllerTest::getEmployee()
{
    // get monthly paid employee
    string ssn1 = "1";
    employee_types::type t1 = employee_types::MONTHLY_PAID_EMPLOYEE;
    QVERIFY(m_controller->addEmployee(t1, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QCOMPARE(t1, m_controller->getEmployee(ssn1)->getType());

    // get hourly paid employee
    string ssn2 = "2";
    employee_types::type t2 = employee_types::HOURLY_PAID_EMPLOYEE;
    QVERIFY(m_controller->addEmployee(t2, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QCOMPARE(t2, m_controller->getEmployee(ssn2)->getType());

    // get salesman employee
    string ssn3 = "3";
    employee_types::type t3 = employee_types::SALESMAN_EMPLOYEE;
    QVERIFY(m_controller->addEmployee(t3, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QCOMPARE(t3, m_controller->getEmployee(ssn3)->getType());

    // verify all fields of monthly paid employee
    string ssn4 = "1234", firstName = "nana", lastName = "fdejfej";
    double monthlySalary = 1.0, hourlySalary = 2.0, doneHours = 3.0, bonus = 4.0;
    bool outcomeClaim = true;
    QVERIFY(m_controller->addEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, firstName, lastName, ssn4, monthlySalary, hourlySalary, doneHours, bonus, outcomeClaim));
    QCOMPARE(ssn4 , m_controller->getEmployeeSsn(ssn4));
    QCOMPARE(firstName , m_controller->getEmployeeFirstName(ssn4));
    QCOMPARE(lastName , m_controller->getEmployeeLastName(ssn4));
    QCOMPARE(monthlySalary, m_controller->getEmployeeMonthlySalary(ssn4));
    QCOMPARE(0.0, m_controller->getEmployeeHourlySalary(ssn4));
    QCOMPARE(0.0, m_controller->getEmployeeDoneHours(ssn4));
    QCOMPARE(0.0, m_controller->getEmployeeBonus(ssn4));
    QCOMPARE(false, m_controller->getEmployeeOutcomeClaim(ssn4));
}



QTEST_MAIN(EmployeeControllerTest)

#include "EmployeeControllerTest.moc"
