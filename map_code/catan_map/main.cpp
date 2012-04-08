#include <QtGui/QApplication>
#include "catan_map.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    catan_map w;
    w.show();

    return a.exec();
}
