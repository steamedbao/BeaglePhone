#ifndef PAGE_H
#define PAGE_H
#include <QWidget>
#include "serial.h"
#include "myinputpanelcontext.h"

class Page : public QWidget
{
    Q_OBJECT
public:
    Page(QWidget *parent = 0, MyInputPanelContext *ic = 0);
    ~Page();
    Serial *getSerial() {return serialPort;}
    void getKeyboard();
protected:
    Serial *serialPort;
    MyInputPanelContext *inputPanel;
};

#endif // PAGE_H
