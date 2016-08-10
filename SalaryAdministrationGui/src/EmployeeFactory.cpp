/*
 * EmployeeFactory.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include "EmployeeFactory.h"
#include "MonthlyPaidEmployee.h"
#include "HourlyPaidEmployee.h"
#include "SalesmanEmployee.h"

using namespace std;


Employee *EmployeeFactory::getEmployee(int employeeType)
{
	switch(employeeType) {
		case 1:
			return new MonthlyPaidEmployee("Pertti Kanasielu", "12345678-123", 3000.50);
		case 2:
			return new HourlyPaidEmployee("Pallas Athenes", "12345678-123", 20.00, 180.00);
		case 3:
			return new SalesmanEmployee("Paavo Pesusieni", "12345678-123", 2500.00, 30, true);
		default:
			cout << "Invalid employee type: " << employeeType << "\n";
		return NULL;
	}
}

Employee *EmployeeFactory::getEmployee(string employeeType)
{
	if(employeeType == "MonthlyPaidEmployee")
		return new MonthlyPaidEmployee("Pertti Kanasielu", "12345678-123", 3000.50);
	else if(employeeType == "HourlyPaidEmployee")
		return new HourlyPaidEmployee("Pallas Athenes", "12345678-123", 20.00, 180.00);
	else if( employeeType == "SalesmanEmployee")
		return new SalesmanEmployee("Paavo Pesusieni", "12345678-123", 2500.00, 30, true);
	else {
		cout << "Invalid employee type: " << employeeType << "\n";
		return NULL;
	}
}



////============================================================================
//// Name        : Example.cpp_old
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include<vector>
//#include<iostream>
//using namespace std;
//
//
//
//
//class Stooge
//{
//  public:
//    // Factory Method
//    static Stooge *make_stooge(int choice);
//    virtual void slap_stick() = 0;
//};
//
//int main()
//{
//  vector<Stooge*> roles;
//  int choice;
//  while (true)
//  {
//    cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
//    cin >> choice;
//    if (choice == 0)
//      break;
//    roles.push_back(Stooge::make_stooge(choice));
//  }
//  for (int i = 0; i < roles.size(); i++)
//    roles[i]->slap_stick();
//  for (int i = 0; i < roles.size(); i++)
//    delete roles[i];
//}
//
//class Larry: public Stooge
//{
//  public:
//    void slap_stick()
//    {
//        cout << "Larry: poke eyes\n";
//    }
//};
//class Moe: public Stooge
//{
//  public:
//    void slap_stick()
//    {
//        cout << "Moe: slap head\n";
//    }
//};
//class Curly: public Stooge
//{
//  public:
//    void slap_stick()
//    {
//        cout << "Curly: suffer abuse\n";
//    }
//};
//
//Stooge *Stooge::make_stooge(int choice)
//{
//  if (choice == 1)
//    return new Larry;
//  else if (choice == 2)
//    return new Moe;
//  else
//    return new Curly;
//}

