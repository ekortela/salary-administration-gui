#include "EmployeeView.h"


void EmployeeView::printEmployeeInfoAll(vector<Employee*> model) {
	for (unsigned int i = 0; model.size() > i; i++) {
		model[i]->printInfo();
		cout << "\n";
	}
}