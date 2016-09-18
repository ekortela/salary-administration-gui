//============================================================================
// Name        : IController.h
// Author      : Aapo Keskimolo
// Description : Interface that handles all communication from View to the
//               Controller. The Controller will implement all its handlers
//               that may be used for requesting operations from the Controller.
//============================================================================

#pragma once

#ifndef ICONTROLLER_H
#define ICONTROLLER_H

class IController
{
public:
  virtual ~IController() {}
  virtual void handleEventCreateEmployee(employee_types::type typ,
                           string newFirstName, string newLastName, string newSsn,
                           double newMonthlySalary, double newHourlySalary,
                           double newDoneHours, double newBonus, bool newOutcomeClaim) = 0;
  virtual void handleEventUpdateEmployee(string newSsn,
                           string newFirstName, string newLastName,
                           double newMonthlySalary, double newHourlySalary,
                           double newDoneHours, double newBonus, bool newOutcomeClaim) = 0;
  virtual void handleEventRequestViewUpdate() = 0;
  virtual void handleEventRemoveEmployee(string ssn) = 0;
  virtual void handleEventClearEmployees() = 0;
  virtual Employee* handleEventGetEmployee(string ssn) = 0;
  virtual void handleEventSaveModelStateToFile(string filename) = 0;
  virtual void handleEventLoadModelDataFromFile(string filename, bool &firstRun) = 0;
};


#endif // ICONTROLLER_H
