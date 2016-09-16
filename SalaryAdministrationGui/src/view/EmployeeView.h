//============================================================================
// Name        : EmployeeView.h
// Author      : Aapo Keskimolo, Elisa Kortela
// Description : View component of the MVC design pattern. The View inherits
//               QMainWindow as the parent widget. The View communicates with
//               the Controller via a handler interface, which is implemented
//               by the Controller.
//============================================================================

#pragma once

#include <QMainWindow>
#include <QtWidgets>
#include "Employee.h"
#include "MonthlyPaidEmployee.h"
#include "HourlyPaidEmployee.h"
#include "SalesmanEmployee.h"
#include "IController.h"


class EmployeeView: public QMainWindow {

    Q_OBJECT

public:
    explicit EmployeeView(QWidget *parent = 0);
    ~EmployeeView();
    void registerObserver(IController *m_observer);
    void addToEmployeeList(string firstName, string lastName, string payType);
    void updateEmployeeList(vector<Employee *> model);
    void popInfoBox(string message);
    void popErrorBox(string message);
    bool popQuestionBox(string title, string message);
    void popWelcomeScreen();
    void saveCurrentModelStateToFile(const string filepath = MODEL_STATE_FILEPATH);
    void loadLastModelStateFromFile(const string filepath = MODEL_STATE_FILEPATH);

private:
    unsigned int *m_treeWidgetSelectedItem;
    int rowHeight;
    QLineEdit *m_lastNameEdit, *m_firstNameEdit, *m_SSNEdit, *m_hoursDoneEdit,
                *m_hourlySalaryEdit, *m_monthlySalaryEdit, *m_bonusEdit, *m_calculatedSalaryEdit, *m_combinedSalaryEdit;
    QLabel *m_lastNameLabel, *m_firstNameLabel, *m_SSNLabel, *m_payTypeLabel,
            *m_monthlySalaryLabel, *m_outcomeClaimLabel, *m_hoursDoneLabel,
            *m_hourlySalaryLabel, *m_displayInfo, *m_bonusLabel, *m_calculatedSalaryLabel, *m_combinedSalaryLabel;
    QComboBox *m_payTypeMenu;
    QPushButton *m_clearFormButton, *m_saveButton, *m_deleteButton;
    QCheckBox *m_outcomeClaimCheckBox;
    QWidget *m_layoutContainer, *m_menuWidget;
    QHBoxLayout *m_mainLayout, *m_salaryView;
    QVBoxLayout *m_layoutFrame, *m_rightLayout;
    QScrollArea *m_scrollArea;
    QGridLayout *m_leftLayout;
    QTreeWidget *m_treeWidget;
    QMenuBar *m_menuBar;
    QMenu *m_fileMenu;
    QList<QTreeWidgetItem *> employeeList;
    QAction *m_saveAsAction, *m_loadAction, *m_newAction, *m_aboutAction, *m_quitAction;

    QFile *m_xmlFile;
    QXmlStreamReader *m_xmlReader;

    IController *m_observer = nullptr;

    void createMenuBar();
    void createTreeWidget();
    void createEmployeeEditorView();
    void setInformationFormWidgetVisibility(bool mSal, bool hDone, bool hSal, bool oClaim, bool bonus, bool calcSal);
    void clearForm();
    QString getQStringFromXml(string parameterName);
    void updateLabels();
    bool checkIfSSNExists(QString ssn);
    bool popSaveEmployeesBox();
    bool popLoadEmployeesBox();
    void updateEmployeeInformation(string ssn);

    const QString xml_config_filename = "strings.xml";
    const string CONFIGURATION_FILEPATH = "setup.cfg";
    static string const MODEL_STATE_FILEPATH; // declared in cpp

    // string configLastUsedConfigFilepath
    string configLastModelStateFilepath = MODEL_STATE_FILEPATH;

    friend inline std::ofstream& operator<<(std::ofstream& os, const EmployeeView& e) {
        os << e.configLastModelStateFilepath;
        return os;
    }

    friend inline std::ifstream& operator>>(std::ifstream& is, EmployeeView& e) {
        is >> e.configLastModelStateFilepath;
        return is;
    }

    void saveCurrentConfig();
    void loadLastSavedConfig();


private slots:
    void handleSaveButtonClick();
    void handleDeleteButtonClick();
    void handleTreeWidgetDoubleClick();
    void handleTreeWidgetClick();
    void handlePayTypeChange();
    void handleClearFormButton();
    void handleExitClick();
    void handleSaveAsClick();
    void handleLoadClick();
    void handleNewClick();
    void handleAboutClick();
    void handleAboutToQuit();
};
