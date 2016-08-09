/*
 * HourlyPaidEmployee.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include "HourlyPaidEmployee.h"


HourlyPaidEmployee::HourlyPaidEmployee(string newName, string newSocialSecurityNumber, double newHourlySalary, double newDoneHours)
{
	setName(newName);
	setSocialSecurityNumber(newSocialSecurityNumber);
	setHourlySalary(newHourlySalary);
}

HourlyPaidEmployee::~HourlyPaidEmployee() {}

void HourlyPaidEmployee::setHourlySalary(double newHourlySalary) {
	hourlySalary = newHourlySalary;
}


double HourlyPaidEmployee::getHourlySalary() {
	return hourlySalary;
}


void HourlyPaidEmployee::setDoneHours(double newDoneHours) {
	doneHours = newDoneHours;
}


double HourlyPaidEmployee::getDoneHours() {
	return doneHours;
}

double HourlyPaidEmployee::getSalary() {
  return hourlySalary*doneHours;
}


