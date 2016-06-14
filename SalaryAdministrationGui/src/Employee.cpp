//============================================================================
// Name        : Employee.cpp
// Author      : Aapo Keskimolo
// Description : Class implementations for Employee types by using Factory Pattern
//============================================================================

#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Employee
{
  private:
	// common attributes
	string name;
    string socialSecurityNumber;
  public:
    // common methods
    void setName(string newName) { name = newName; }
    string getName() { return name; }
  	void setSocialSecurityNumber(string newSocialSecurityNumber) { socialSecurityNumber = newSocialSecurityNumber; }
  	string getSocialSecurityNumber() { return name; }

	// we want to be able to dynamically create classes with different attributes
  	// one suitable way to do this is to use the factory design pattern
    static Employee *getEmployee(string employeeType);
    virtual double getSalary() = 0; // implemented in all sub-classes separately
};


class MonthlyPaidEmployee: public Employee
{
  private:
    double monthlySalary;
  public:

    void setMonthlySalary(double newMonthlySalary) { monthlySalary = newMonthlySalary; }
    double getMonthlySalary() { return monthlySalary; }

    double getSalary()
    {
      return monthlySalary;
    }

    MonthlyPaidEmployee::MonthlyPaidEmployee(string newName, string newSocialSecurityNumber, double newMonthlySalary)
    {
    	setName(newName);
    	setSocialSecurityNumber(newSocialSecurityNumber);
    	setMonthlySalary(newMonthlySalary);
    }
};


class HourlyPaidEmployee: public Employee
{
  private:
    double hourlySalary;
    double doneHours;
  public:
    void setHourlySalary(double newHourlySalary) { hourlySalary = newHourlySalary; }
    double getHourlySalary() { return hourlySalary; }
    void setDoneHours(double newDoneHours) { doneHours = newDoneHours; }
    double getDoneHours() { return doneHours; }

	double getSalary() {
      return hourlySalary*doneHours;
    }

    HourlyPaidEmployee::HourlyPaidEmployee(string newName, string newSocialSecurityNumber, double newHourlySalary, double newDoneHours)
    {
    	setName(newName);
    	setSocialSecurityNumber(newSocialSecurityNumber);
    	setHourlySalary(newHourlySalary);
    }
};

class Salesman: public Employee
{
  private:
  	double monthlySalary;
    double bonus;
    double realizedOutcome;
    bool outcomeClaim;
  public:
    void setMonthlySalary(double newMonthlySalary) { monthlySalary = newMonthlySalary; }
    double getMonthlySalary() { return monthlySalary; }
    void setBonus(double newBonus) { bonus = newBonus; }
    double getBonus() { return bonus; }
    void setOutcomeClaim(bool newOutcomeClaim) { outcomeClaim = newOutcomeClaim; }
    void setRealizedOutcome(double newRealizedOutcome) { realizedOutcome = newRealizedOutcome; }

    double getSalary()
    {
      return realizedOutcome;
    }

    Salesman::Salesman(string newName, string newSocialSecurityNumber, double newMonthlySalary, double newBonus, bool newOutcomeClaim)
    {
    	setName(newName);
    	setSocialSecurityNumber(newSocialSecurityNumber);
    	setMonthlySalary(newMonthlySalary);
    	setBonus(newBonus);
    	setOutcomeClaim(newOutcomeClaim);

    	// calculate outcome
        if (outcomeClaim)
          setRealizedOutcome( (100+bonus)/100*monthlySalary );
        else
          setRealizedOutcome( monthlySalary );
    }

};



Employee *Employee::getEmployee(string employeeType)
{
  if (employeeType == "MonthlyPaidEmployee")
    return new MonthlyPaidEmployee("Pertti Kanasielu", "12345678-123", 3000.50);
  else if (employeeType == "HourlyPaidEmployee")
    return new HourlyPaidEmployee("Pallas Athenes", "12345678-123", 20.00, 180.00);
  else
    return new Salesman("Paavo Pesusieni", "12345678-123", 2500.00, 30, true);
}


int main()
{
  cout << " Started\n";

  vector<Employee*> EmployeeList;

  EmployeeList.push_back(Employee::getEmployee("Salesman"));

  cout << EmployeeList[0]->getSalary() << endl;
  cout << EmployeeList[0]->getName() << endl;


//  MonthlyPaidEmployee *pEmployee0 = (MonthlyPaidEmployee *) &EmployeeList[0]; // downcast
//  cout << "Name " << pEmployee0->getName() << "\n";


//  MonthlyPaidEmployee tuomo("Tuomo Laitakulkija", "12345678-123", 3000.00);
//  cout << "Name " << tuomo.getName() << "\n";

//  MonthlyPaidEmployee *pMonthlyPaidEmployee = (MonthlyPaidEmployee *) &EmployeeList[0]; // downcast
////  pMonthlyPaidEmployee->setName("Termo");
//  cout << "Name " << pMonthlyPaidEmployee->getName() << "\n";
////  EmployeeList[0]->getSalary();
//
//
//  EmployeeList.push_back(Employee::getEmployee("HourlyPaidEmployee"));
////  EmployeeList[1]->setHourlySalary(3000.00);
////  EmployeeList[1]->setDoneHours(180.00);
//
//  EmployeeList.push_back(Employee::getEmployee("Salesman"));
////  EmployeeList[2]->setMonthlySalary(2500.00);
////  EmployeeList[2]->setBonus(0.50);
////  EmployeeList[2]->setOutcomeClaim(true);
//
//  for (int i = 0; i < EmployeeList.size(); i++)
//    cout << EmployeeList[i]->getSalary() << "\n";
//  for (int i = 0; i < EmployeeList.size(); i++)
//    delete EmployeeList[i];
}

