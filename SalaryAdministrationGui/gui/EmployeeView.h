#pragma once

#include "Employee.h"
#include <QtWidgets>
#include <QVBoxLayout>
#include <QHBoxLayout>

class EmployeeView: public QWidget {
public:
    EmployeeView(QWidget *view);
	void printEmployeeInfoAll(vector<Employee *> model);

private:
    QWidget *view;
    QHBoxLayout *mainLayout;
    void initialize();
    void createTreeWidget(QHBoxLayout *mainLayout);
    void createEemployeeInformationView(QHBoxLayout *mainLayout);
};
