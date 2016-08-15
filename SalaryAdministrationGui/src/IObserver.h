#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver
{
public:
  virtual ~IObserver() {}

  virtual void handleEventAddEmployee(employee_types::type typ,
                           string newFirstName, string newLastName, string newSsn,
                           double newMonthlySalary, double newHourlySalary,
                           double newDoneHours, double newBonus, bool newOutcomeClaim) = 0;

  virtual void handleEventPrintEmployeeInfo() = 0;

//  virtual void handleEventSetActiveEmployee() = 0;



};


#endif // IOBSERVER_H
