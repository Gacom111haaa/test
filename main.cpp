#include "mainwindow.h"
#include <QApplication>
#include "map.h"
#include "mainwindow1.h"
#include "test.h"
#include "clogfile.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow1 w;
    w.show();
//    map *map_00 = new map();
//    map_00->show();
//    test w1;
//    w1.show();
    return a.exec();
}
