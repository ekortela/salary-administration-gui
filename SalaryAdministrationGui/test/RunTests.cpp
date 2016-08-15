#include <QtTest/QtTest>
#include <QApplication>
#include "EmployeeControllerTest.h"
#include "EmployeeController.h"
#include "EmployeeView.h"

int main(int argc, char *argv[])

{

  QApplication app(argc, argv);

  EmployeeView view;
  EmployeeController controller = EmployeeController(&view);

  EmployeeControllerTest ct;

  QTest::qExec(&ct);

  return 0;

}
