#include <QApplication>

#include "viewexample.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ViewExample v(800, 800);
    v.show();

    return a.exec();
}
