#ifndef EMPLOYEECONTROLLERTEST_H
#define EMPLOYEECONTROLLERTEST_H

#include <QtTest/QtTest>

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

#endif // EMPLOYEECONTROLLERTEST_H
