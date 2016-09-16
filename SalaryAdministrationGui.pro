#============================================================================
# Name        : SalaryAdministrationGui.pro
# Author      : Aapo Keskimolo
# Description : Main QMakefile for SalaryAdministrationGui
#============================================================================

QT += widgets

TARGET = SalaryAdministrationGui

message(" ~~~ Project Build directory: $$OUT_PWD ~~~")

# build directories
CONFIG(release,release|debug) {
    static {
        DESTDIR = static
        message("~~~ Release: static build ~~~")
    }
    else:       DESTDIR = $$PWD/build/release
    MOC_DIR = $$DESTDIR/.moc
    OBJECTS_DIR = $$DESTDIR/.obj
}
else {
    static {
        DESTDIR = static
        message("~~~ debug: static build ~~~")
    }
    else:       DESTDIR = $$PWD/build/debug
    OBJECTS_DIR = $$DESTDIR/.obj
    MOC_DIR = $$DESTDIR/.moc
}

# Copy resource files to target directory
RESOURCEDIR = SalaryAdministrationGui/res
win32 {
    DESTDIR_WIN = $${DESTDIR}
    DESTDIR_WIN ~= s,/,\\,g
    SOURCEDIR_WIN = $${RESOURCEDIR}
    SOURCEDIR_WIN ~= s,/,\\,g
    QMAKE_POST_LINK += $$quote(cmd /c copy /y $${SOURCEDIR_WIN} $${DESTDIR_WIN}$$escape_expand(\n\t))
    message("~~~ Win: qmake_post_link: $$QMAKE_POST_LINK ~~~")
}
else {
    QMAKE_POST_LINK += $$quote(cp $${RESOURCEDIR}/* $${DESTDIR}$$escape_expand(\n\t))
    message("~~~ Linux: qmake_post_link: $$QMAKE_POST_LINK ~~~")
}

# include sources
INCLUDEPATH += SalaryAdministrationGui/src/controller \
               SalaryAdministrationGui/src/model \
               SalaryAdministrationGui/src/view \
               SalaryAdministrationGui/src/main

HEADERS += SalaryAdministrationGui/src/controller/EmployeeController.h \
           SalaryAdministrationGui/src/controller/EmployeeControllerException.h \
           SalaryAdministrationGui/src/controller/IController.h \
           SalaryAdministrationGui/src/model/Employee.h \
           SalaryAdministrationGui/src/model/EmployeeFactory.h \
           SalaryAdministrationGui/src/model/EmployeeFactoryException.h \
           SalaryAdministrationGui/src/model/HourlyPaidEmployee.h \
           SalaryAdministrationGui/src/model/MonthlyPaidEmployee.h \
           SalaryAdministrationGui/src/model/SalesmanEmployee.h \
           SalaryAdministrationGui/src/view/EmployeeView.h

SOURCES += SalaryAdministrationGui/src/controller/EmployeeController.cpp \
           SalaryAdministrationGui/src/main/Main.cpp \
           SalaryAdministrationGui/src/model/Employee.cpp \
           SalaryAdministrationGui/src/model/EmployeeFactory.cpp \
           SalaryAdministrationGui/src/model/HourlyPaidEmployee.cpp \
           SalaryAdministrationGui/src/model/MonthlyPaidEmployee.cpp \
           SalaryAdministrationGui/src/model/SalesmanEmployee.cpp \
           SalaryAdministrationGui/src/view/EmployeeView.cpp
