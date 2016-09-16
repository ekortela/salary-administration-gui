//============================================================================
// Name        : Main.cpp
// Author      : Aapo Keskimolo
// Description : The Main executor for Salary Administration GUI. Initializes
//               the QApplication, View, Controller and Message logger with
//               with log file for handling the GUI operations.
//============================================================================

#include <QApplication>
#include "EmployeeController.h"
#include <stdio.h>
#include <stdlib.h>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();

    QDateTime dateTime(QDateTime::currentDateTime());
    QString timeStr(dateTime.toString("dd-MM-yyyy HH:mm:ss:zzz"));
    QString contextString(QString("(%1, %2, %3): ").arg(context.file).arg(context.function).arg(context.line));

    QFile outFile("SalaryAdministrationGui.log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream stream(&outFile);


    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        stream << timeStr << " - DEBUG - " << contextString << localMsg.constData() << endl;
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        stream << timeStr << " - INFO - " << contextString << localMsg.constData() << endl;
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        stream << timeStr << " - WARNING - " << contextString << localMsg.constData() << endl;
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        stream << timeStr << " - CRITICAL - " << contextString << localMsg.constData() << endl;
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        stream << timeStr << " - FATAL - " << contextString << localMsg.constData() << endl;
    }
}


int main(int argc, char *argv[]) {

//    QLoggingCategory::setFilterRules("*.debug=false");

    QLocale::setDefault(QLocale::c());

    QApplication app(argc, argv);

    qInstallMessageHandler(myMessageOutput);

    EmployeeView view;
    EmployeeController controller = EmployeeController(&view);
    QObject::connect(&app, SIGNAL(aboutToQuit()), &view, SLOT(handleAboutToQuit()));

    return app.exec();
}
