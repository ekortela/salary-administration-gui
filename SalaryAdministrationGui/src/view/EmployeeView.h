//============================================================================
// Name        : EmployeeView.h
// Author      : Aapo Keskimolo, Elisa Kortela
// Description : View component of the MVC design pattern. The View inherits
//               QMainWindow as the parent widget. The View communicates with
//               the Controller via a handler interface, which is implemented
//               by the Controller.
//============================================================================

#pragma once

#include <QtWidgets>
#include "Employee.h"
#include "MonthlyPaidEmployee.h"
#include "HourlyPaidEmployee.h"
#include "SalesmanEmployee.h"
#include "IObserver.h"

class EmployeeView: public QMainWindow {

    Q_OBJECT

public:
    explicit EmployeeView(QWidget *parent = 0);
    ~EmployeeView();
    void registerObserver(IObserver *m_observer);
    void addToEmployeeList(string firstName, string lastName, string payType);
    void updateEmployeeList(vector<Employee *> model);
    void popInfoBox(string message);
    void popErrorBox(string message);

private:
    const QString config_filename = "../../res/config.xml";
    unsigned int *m_treeWidgetSelectedItem;
    int rowHeight;
    QLineEdit *m_lastNameEdit, *m_firstNameEdit, *m_SSNEdit, *m_hoursDoneEdit,
                *m_hourlySalaryEdit, *m_monthlySalaryEdit, *m_bonusEdit;
    QLabel *m_lastNameLabel, *m_firstNameLabel, *m_SSNLabel, *m_payTypeLabel,
            *m_monthlySalaryLabel, *m_outcomeClaimLabel, *m_hoursDoneLabel,
            *m_hourlySalaryLabel, *m_displayInfo, *m_bonusLabel;
    QComboBox *m_payTypeMenu;
    QPushButton *m_addNewEmployeeButton, *m_saveButton, *m_deleteButton;
    QCheckBox *m_outcomeClaimCheckBox;
    QWidget *m_layoutContainer, *m_menuWidget;
    QHBoxLayout *m_mainLayout, *m_buttonLayout;
    QVBoxLayout *m_leftLayout, *m_rightLayout, *m_layoutFrame;
    QScrollArea *m_scrollArea;
    QGridLayout *m_employeeInfoGrid;
    QTreeWidget *m_treeWidget;
    QMenuBar *m_menuBar;
    QMenu *m_fileMenu;
    QList<QTreeWidgetItem *> employeeList;

    QFile *m_xmlFile;
    QXmlStreamReader *m_xmlReader;

    IObserver *m_observer;

    void createMenuBar();
    void createTreeWidget();
    void createEmployeeInformationView();
    void setInformationFormWidgetVisibility(bool mSal, bool hDone, bool hSal, bool oClaim, bool bonus);
    bool confirmDeletionMessageBox();
    void clearForm();
    QString getQStringFromConfig(string parameterName);

private slots:
    void handleSaveButtonClick();
    void handleDeleteButtonClick();
    void handleTreeWidgetDoubleClick();
    void handlePayTypeChange();
    void handleAddNewEmployeeButtonClick();
};
