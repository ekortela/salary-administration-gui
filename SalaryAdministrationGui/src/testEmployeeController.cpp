/*
 * testEmployeeFactory.cpp
 *
 *  Created on: 9.8.2016
 *      Author: keskimol
 */

#include <vector>
#include <iostream>
#include "assert.h"
#include "EmployeeFactory.h"
#include "EmployeeView.h"
#include "EmployeeController.h"

using namespace std;


int main(void)
{
	/*
	View vastaa tassa Dummy implementoinnissa graafista kayttoliittymaa. Kun kaytat Controller luokkaa
	sinun tarvitsee vain alustaa se GUI:ssa (konstruktorissa tai jossain create() metodissa) ja sitten
	kaikki mallin hallitsemiseen tarvitsemasi metodit ovat GUI:n kaytossa. Aina kun mallia muutetaan,
	muista kutsua .updateView() metodia ja se paivittaa GUI:n widget parametrit.
	*/

	EmployeeView *pView = new EmployeeView(); // .... Tama vastaa siis GUI:ta
	EmployeeController *pController = new EmployeeController(pView); // ... Tata luokkaa _kaytetaan_ GUI:ssa

	// Esimerkki. 
	// MainWindow.h / MainWindow.cpp (metodi tai konstruktori)
	// EmployeeController c = EmployeeController(this);
	// Se on siina! Nyt kaikki kontrollerin metodit ovat GUI:n kaytossa!

	pController->addHourlyPaidEmployee("Paavo Narkas", "123456-123", 20.0, 180.0);
	pController->addMonthlyPaidEmployee("Teuvo Maantienkuningas", "123456-1244", 3000.0);

	string ssn = "383838-11919";
	pController->addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);

	// Display employees with dummy View 
	cout << "\n *** TEST *** Display all employee information by using dummy view... \n";
	pController->updateView();

	// Test
	cout << "\n *** TEST *** Try to add employee with pre-existing SSN... \n";
	int nEmployees = pController->getEmployeeCount();
	pController->addSalesmanEmployee("Risto Varakas", ssn, 1500.50, 30.0, true);
	assert(nEmployees == pController->getEmployeeCount());

	// Test
	cout << "\n *** TEST *** Try to remove employee that does not exist... \n";
	nEmployees = pController->getEmployeeCount();
	pController->removeEmployeeBySsn("absdjdjd");
	assert(nEmployees == pController->getEmployeeCount());

	// Test
	cout << "\n *** TEST *** Change existing employee name... \n";
	string newName = "Risto Uusisukunimi";
	pController->setEmployeeName(ssn, newName);
	assert(pController->getEmployeeName(ssn) == newName);

	// Test
	cout << "\n *** TEST *** Remove employee... \n";
	ssn = "This SSN will be removed";
	//nEmployees = pController->getEmployeeCount();
	//cout << pController->getEmployeeCount() << "\n";
	pController->updateView();
	pController->addSalesmanEmployee("", ssn, 0.0, 0.0, true);
	pController->removeEmployeeBySsn(ssn);
	assert(pController->getEmployeeIndex(ssn) == -1);
	//cout << pController->getEmployeeCount() << "\n";
	//assert(pController->getEmployeeCount() == (nEmployees-1));


	// Display employees
	cout << "\nFinal employee list:\n";
	pController->updateView();

}
