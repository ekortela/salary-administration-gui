#pragma once

#include "Employee.h"
#include <QtWidgets>

class EmployeeView: public QMainWindow {

    Q_OBJECT

public:
    explicit EmployeeView(QWidget *parent = 0);

    QLineEdit *m_lastNameEdit, *m_firstNameEdit, *m_SSNEdit, *m_hoursDoneEdit,
                *m_salaryEdit, *m_realizedIncomeEdit, *m_outcomeClaimEdit;
    QComboBox *m_payTypeMenu;
    QPushButton *m_addNewEmployeeButton, *m_saveButton, *m_deleteButton;
    QTreeWidget *m_treeWidget;

    void printEmployeeInfoAll(vector<Employee *> model);

private:
    QLabel *m_lastNameLabel, *m_firstNameLabel, *m_SSNLabel, *m_payTypeLabel,
            *m_realizedIncomeLabel, *m_outcomeClaimLabel, *m_hoursDoneLabel,
            *m_salaryLabel, *m_displayInfo;
    QWidget *m_treeWidgetContainer, *m_scrollAreaContainer;
    QHBoxLayout *m_mainLayout;
    QVBoxLayout *m_rightLayout;
    QScrollArea *m_scrollArea;
    QGridLayout *m_leftLayout;

    void createTreeWidget(QHBoxLayout *m_mainLayout);
    void createEemployeeInformationView(QHBoxLayout *m_mainLayout);

private slots:
    void handleSaveButtonClick();
    void handleDeleteButtonClick();
};
