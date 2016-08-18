#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver
{
public:
  virtual ~IObserver() {}

  virtual bool handleEventAddEmployee(employee_types::type typ,
                           string newFirstName, string newLastName, string newSsn,
                           double newMonthlySalary, double newHourlySalary,
                           double newDoneHours, double newBonus, bool newOutcomeClaim) = 0;

  virtual void handleEventPrintEmployees() = 0;

  virtual void handleEventRequestViewUpdate() = 0;

  virtual bool handleEventRemoveEmployee(string ssn) = 0;

  virtual Employee* handleEventGetEmployee(string ssn) = 0;

};


#endif // IOBSERVER_H
