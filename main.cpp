#include "mainwindow.h"
#include <QApplication>
#include <QImageReader>
#include "myinputpanelcontext.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyInputPanelContext *ic = new MyInputPanelContext;
    a.setInputContext(ic);
    MainWindow w(0,ic);




    return a.exec();
}
