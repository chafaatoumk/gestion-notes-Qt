#include "flowcontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlowController controller;
    controller.exec();
    return a.exec();
}
