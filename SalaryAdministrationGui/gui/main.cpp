#include "main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *view = new QWidget;

    EmployeeController controller = EmployeeController(view);

    return app.exec();
}
