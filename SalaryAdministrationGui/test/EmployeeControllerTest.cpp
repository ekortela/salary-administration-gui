#if 0
#define QT_NO_DEBUG_OUTPUT
#endif
#include <QtTest/QtTest>
#include <QCoreApplication>
#include <QtCore/QDebug>
#include "EmployeeController.h"
#include "EmployeeView.h"


void noMessageOutput(QtMsgType, const QMessageLogContext&, const QString &) { }

using namespace ec;

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
    void createEmployee();
    void removeEmployee();
    void setGetEmployeeFirstName();
    void setGetEmployeeLastName();
    void setGetEmployeeSsn();
    void setGetEmployeeHourlySalary();
    void setGetEmployeeMonthlySalary();
    void setGetEmployeeBonus();
    void setGetEmployeeOutcomeclaim();
    void setGetEmployeeDoneHours();
    void getEmployee();
    void updateEmployee();
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

void EmployeeControllerTest::createEmployee()
{
    int unsigned n = 3;
    string ssn = "1";
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->createEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", "2", 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->createEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", "3", 0.0, 0.0, 0.0, 0.0, false));
    QCOMPARE(n , m_controller->getEmployeeCount());

    // try to add employee with ssn that already exists
    QVERIFY_EXCEPTION_THROWN(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false), EmployeeAlreadyExistsException);

    // try to add employee of invalid employee type
    QVERIFY_EXCEPTION_THROWN(m_controller->createEmployee(employee_types::UNKNOWN, "", "", "4", 0.0, 0.0, 0.0, 0.0, false), EmployeeTypeInvalidException);
}

void EmployeeControllerTest::removeEmployee()
{
    string ssn = "1";\
    int unsigned n = 0;
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->removeEmployee(ssn));
    QCOMPARE(n, m_controller->getEmployeeCount());
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->removeEmployee(ssn));

    // try to remove employee with ssn that does not exist
    QVERIFY_EXCEPTION_THROWN(m_controller->removeEmployee("does_not_exist"), SsnDoesNotExistException);
}

void EmployeeControllerTest::setGetEmployeeFirstName() {
    string ssn = "1";
    string firstName = "new_name";
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeFirstName(ssn, firstName));
    QCOMPARE(firstName, m_controller->getEmployeeFirstName(ssn));

    // try to set value for ssn that does not exist
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeFirstName("not_exist", ""), SsnDoesNotExistException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeFirstName("not_exist"), SsnDoesNotExistException);
}


void EmployeeControllerTest::setGetEmployeeLastName()  {
    string ssn = "1";
    string lastName = "new_name";
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeLastName(ssn, lastName));
    QCOMPARE(lastName, m_controller->getEmployeeLastName(ssn));

    // try to set value for ssn that does not exist
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeLastName("not_exist", ""), SsnDoesNotExistException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeLastName("not_exist"), SsnDoesNotExistException);
}

void EmployeeControllerTest::setGetEmployeeSsn()  {
    string ssn = "1";
    string newSsn = "123";
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeSsn(ssn, newSsn));
    QCOMPARE(newSsn, m_controller->getEmployeeSsn(newSsn));

    // try to set value for ssn that does not exist
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeSsn("not_exist", ""), SsnDoesNotExistException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeSsn("not_exist"), SsnDoesNotExistException);
}

void EmployeeControllerTest::setGetEmployeeHourlySalary()  {
    // hourly salary
    string ssn = "1";
    double newHourlySalary = 1.0;
    QVERIFY(m_controller->createEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeHourlySalary(ssn, newHourlySalary));
    QCOMPARE(newHourlySalary, m_controller->getEmployeeHourlySalary(ssn));

    // try to set monthly salary for salesman employee
    string ssn2 = "2";
    double newMonthlySalary2 = 2.0;
    QVERIFY(m_controller->createEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeHourlySalary(ssn2, newMonthlySalary2), EmployeeTypeInvalidException);

    // try to set monthly salary for monthly paid employee
    string ssn3 = "3";
    double newMonthlySalary3 = 3.0;
    QVERIFY(m_controller->createEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeHourlySalary(ssn2, newMonthlySalary3), EmployeeTypeInvalidException);

    // try to set value for ssn that does not exist
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeHourlySalary("not_exist", 0.0), SsnDoesNotExistException);
}

void EmployeeControllerTest::setGetEmployeeMonthlySalary()  {

    // monthly paid employee
    string ssn1 = "1";
    double newMonthlySalary1 = 1.0;
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeMonthlySalary(ssn1, newMonthlySalary1));
    QCOMPARE(newMonthlySalary1, m_controller->getEmployeeMonthlySalary(ssn1));

    // salesman employee
    string ssn2 = "2";
    double newMonthlySalary2 = 2.0;
    QVERIFY(m_controller->createEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeMonthlySalary(ssn2, newMonthlySalary2));
    QCOMPARE(newMonthlySalary2, m_controller->getEmployeeMonthlySalary(ssn2));

    // try to set monthly salary for hourly paid employee
    string ssn3 = "3";
    double newMonthlySalary3 = 3.0;
    QVERIFY(m_controller->createEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeMonthlySalary(ssn3, newMonthlySalary3), EmployeeTypeInvalidException);

    // try to set value for ssn that does not exist
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeMonthlySalary("not_exist", 0.0), SsnDoesNotExistException);
}

void EmployeeControllerTest::setGetEmployeeBonus()  {

    // salesman employee
    string ssn1 = "1";
    double newBonus1= 1.0;
    QVERIFY(m_controller->createEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeBonus(ssn1, newBonus1));
    QCOMPARE(newBonus1, m_controller->getEmployeeBonus(ssn1));

    // try to set monthly salary for hourly paid employee
    string ssn2 = "2";
    double newBonus2 = 2.0;
    QVERIFY(m_controller->createEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeBonus(ssn2, newBonus2), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeBonus(ssn2), EmployeeTypeInvalidException);

    // try to set monthly salary for monthly paid employee
    string ssn3 = "3";
    double newBonus3= 3.0;
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeBonus(ssn3, newBonus3), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeBonus(ssn3), EmployeeTypeInvalidException);

//    // try to set value for ssn that does not exist
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeBonus("not_exist", 0.0), SsnDoesNotExistException);
}

void EmployeeControllerTest::setGetEmployeeOutcomeclaim()  {

    // salesman employee
    string ssn1 = "1";
    bool newOutcomeClaim1 = true;
    QVERIFY(m_controller->createEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeOutcomeclaim(ssn1, newOutcomeClaim1 ));
    QCOMPARE(newOutcomeClaim1, m_controller->getEmployeeOutcomeClaim(ssn1));

    // try to set outcome claim for hourly paid employee
    string ssn2 = "2";
    double newOutcomeClaim2 = true;
    QVERIFY(m_controller->createEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeOutcomeclaim(ssn2, newOutcomeClaim2), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeOutcomeClaim(ssn2), EmployeeTypeInvalidException);

    // try to set outcome claim for monthly paid employee
    string ssn3 = "3";
    double newOutcomeClaim3 = true;
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeOutcomeclaim(ssn3, newOutcomeClaim3), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeOutcomeClaim(ssn3), EmployeeTypeInvalidException);

    // try to set value for ssn that does not exist
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeOutcomeclaim("not_exist", 0.0), SsnDoesNotExistException);
}

void EmployeeControllerTest::setGetEmployeeDoneHours() {

    // hourly paid employee
    string ssn1 = "1";
    double newDoneHours1 = 1.0;
    QVERIFY(m_controller->createEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->setEmployeeDoneHours(ssn1, newDoneHours1 ));
    QCOMPARE(newDoneHours1, m_controller->getEmployeeDoneHours(ssn1));

    // try to set done hours for monthly paid employee
    string ssn2 = "2";
    double newDoneHours2 = 2.0;
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeDoneHours(ssn2, newDoneHours2), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeDoneHours(ssn2), EmployeeTypeInvalidException);

    // try to set done hours for salesman employee
    string ssn3 = "3";
    double newDoneHours3 = 3.0;
    QVERIFY(m_controller->createEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeDoneHours(ssn3, newDoneHours3), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeDoneHours(ssn3), EmployeeTypeInvalidException);

    // try to set value for ssn that does not exist
    QVERIFY_EXCEPTION_THROWN(m_controller->setEmployeeDoneHours("not_exist", 0.0), SsnDoesNotExistException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeDoneHours("not_exist"), SsnDoesNotExistException);
}

void EmployeeControllerTest::getEmployee()
{
    // get monthly paid employee
    string ssn1 = "1";
    employee_types::type t1 = employee_types::MONTHLY_PAID_EMPLOYEE;
    QVERIFY(m_controller->createEmployee(t1, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QCOMPARE(t1, m_controller->getEmployee(ssn1)->getType());

    // get hourly paid employee
    string ssn2 = "2";
    employee_types::type t2 = employee_types::HOURLY_PAID_EMPLOYEE;
    QVERIFY(m_controller->createEmployee(t2, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QCOMPARE(t2, m_controller->getEmployee(ssn2)->getType());

    // get salesman employee
    string ssn3 = "3";
    employee_types::type t3 = employee_types::SALESMAN_EMPLOYEE;
    QVERIFY(m_controller->createEmployee(t3, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QCOMPARE(t3, m_controller->getEmployee(ssn3)->getType());

    // verify all fields of monthly paid employee
    string ssn4 = "1234", firstName = "nana", lastName = "fdejfej";
    double monthlySalary = 1.0, hourlySalary = 2.0, doneHours = 3.0, bonus = 4.0;
    bool outcomeClaim = true;
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, firstName, lastName, ssn4, monthlySalary, hourlySalary, doneHours, bonus, outcomeClaim));
    QCOMPARE(ssn4 , m_controller->getEmployeeSsn(ssn4));
    QCOMPARE(firstName , m_controller->getEmployeeFirstName(ssn4));
    QCOMPARE(lastName , m_controller->getEmployeeLastName(ssn4));
    QCOMPARE(monthlySalary, m_controller->getEmployeeMonthlySalary(ssn4));
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeHourlySalary(ssn4), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeDoneHours(ssn4), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeBonus(ssn4), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeOutcomeClaim(ssn4), EmployeeTypeInvalidException);
}

void EmployeeControllerTest::updateEmployee() {

    // monthly employee
    string ssn1 = "1", newFirstName = "Teuvo1", newLastName = "Laaksonen1";
    double newMonthlySalary = 1.0;
    QVERIFY(m_controller->createEmployee(employee_types::MONTHLY_PAID_EMPLOYEE, "", "", ssn1, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->updateEmployee(ssn1, newFirstName, newLastName, newMonthlySalary, 0.0, 0.0, 0.0, false));
    QCOMPARE(newFirstName, m_controller->getEmployeeFirstName(ssn1) );
    QCOMPARE(newLastName, m_controller->getEmployeeLastName(ssn1) );
    QCOMPARE(newMonthlySalary, m_controller->getEmployeeMonthlySalary(ssn1) );
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeHourlySalary(ssn1), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeDoneHours(ssn1), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeBonus(ssn1), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeOutcomeClaim(ssn1), EmployeeTypeInvalidException);


    // hourly employee
    string ssn2 = "2", newFirstName2 = "Teuvo2", newLastName2 = "Laaksonen2";
    double newHourlySalary = 2.0, newDoneHours = 200;
    QVERIFY(m_controller->createEmployee(employee_types::HOURLY_PAID_EMPLOYEE, "", "", ssn2, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->updateEmployee(ssn2, newFirstName2, newLastName2, 0.0, newHourlySalary, newDoneHours, 0.0, false));
    QCOMPARE(newFirstName2, m_controller->getEmployeeFirstName(ssn2) );
    QCOMPARE(newLastName2, m_controller->getEmployeeLastName(ssn2) );
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeMonthlySalary(ssn2), EmployeeTypeInvalidException );
    QCOMPARE(newHourlySalary, m_controller->getEmployeeHourlySalary(ssn2));
    QCOMPARE(newDoneHours, m_controller->getEmployeeDoneHours(ssn2));
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeBonus(ssn2), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeOutcomeClaim(ssn2), EmployeeTypeInvalidException);

    // salesman employee
    string ssn3 = "3", newFirstName3 = "Teuvo3", newLastName3 = "Laaksonen3";
    double newMonthlySalary3 = 3.0, newBonus = 20.0;
    bool newOutcomeClaim = true;
    QVERIFY(m_controller->createEmployee(employee_types::SALESMAN_EMPLOYEE, "", "", ssn3, 0.0, 0.0, 0.0, 0.0, false));
    QVERIFY(m_controller->updateEmployee(ssn3, newFirstName3, newLastName3, newMonthlySalary3, 0.0, 0.0, newBonus, newOutcomeClaim));
    QCOMPARE(newFirstName3, m_controller->getEmployeeFirstName(ssn3) );
    QCOMPARE(newLastName3, m_controller->getEmployeeLastName(ssn3) );
    QCOMPARE(newMonthlySalary3, m_controller->getEmployeeMonthlySalary(ssn3) );
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeHourlySalary(ssn3), EmployeeTypeInvalidException);
    QVERIFY_EXCEPTION_THROWN(m_controller->getEmployeeDoneHours(ssn3), EmployeeTypeInvalidException);
    QCOMPARE(newBonus, m_controller->getEmployeeBonus(ssn3));
    QCOMPARE(newOutcomeClaim, m_controller->getEmployeeOutcomeClaim(ssn3));
}

QTEST_MAIN(EmployeeControllerTest)

#include "EmployeeControllerTest.moc"
