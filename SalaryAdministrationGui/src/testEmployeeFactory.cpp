/*
 * testEmployeeFactory.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */


#include <vector>
#include <iostream>
#include "EmployeeFactory.h"
#include "SalesmanEmployee.h"

using namespace std;



int main()
{
  cout << " Started\n";

  vector<Employee*> EmployeeList;

  EmployeeList.push_back( EmployeeFactory::getEmployee(1));

  SalesmanEmployee *pSalesman = (SalesmanEmployee *) &EmployeeList[0]; // downcast

    for (int i = 0; i < EmployeeList.size(); i++)
      EmployeeList[i]->getName();
    for (int i = 0; i < EmployeeList.size(); i++)
      delete EmployeeList[i];

//  EmployeeList.push_back( EmployeeFactory::getEmployee("Salesman"));
//
//  cout << EmployeeList[0]->getSalary() << endl;
//  cout << EmployeeList[0]->getName() << endl;
//
//
//  MonthlyPaidEmployee *pEmployee0 = (MonthlyPaidEmployee *) &EmployeeList[0]; // downcast
//  cout << "Name " << pEmployee0->getName() << "\n";
//
//
//  MonthlyPaidEmployee tuomo("Tuomo Laitakulkija", "12345678-123", 3000.00);
//  cout << "Name " << tuomo.getName() << "\n";
//
//  MonthlyPaidEmployee *pMonthlyPaidEmployee = (MonthlyPaidEmployee *) &EmployeeList[0]; // downcast
////  pMonthlyPaidEmployee->setName("Termo");
//  cout << "Name " << pMonthlyPaidEmployee->getName() << "\n";
////  EmployeeList[0]->getSalary();
//
//
//  EmployeeList.push_back(EmployeeFactory::getEmployee("HourlyPaidEmployee"));
////  EmployeeList[1]->setHourlySalary(3000.00);
////  EmployeeList[1]->setDoneHours(180.00);
//
//  EmployeeList.push_back(EmployeeFactory::getEmployee("SalesmanEmployee"));
////  EmployeeList[2]->setMonthlySalary(2500.00);
////  EmployeeList[2]->setBonus(0.50);
////  EmployeeList[2]->setOutcomeClaim(true);
//
//  for (int i = 0; i < EmployeeList.size(); i++)
//    cout << EmployeeList[i]->getSalary() << "\n";
//  for (int i = 0; i < EmployeeList.size(); i++)
//    delete EmployeeList[i];
}
