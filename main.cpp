  #include "mainwindow.h"
#include <QApplication>
#include <QImageReader>
#include "myinputpanelcontext.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MyInputPanelContext *ic = new MyInputPanelContext;
    a.setInputContext(ic);


    return a.exec();
}
