#include "mainwindow.h"
#include "Logger.h"
#include <QApplication>
#include "cards.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
