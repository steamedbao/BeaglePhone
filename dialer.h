#ifndef DIALER_H
#define DIALER_H

#include <QWidget>
#include "serial.h"
#include "mainwindow.h"

namespace Ui {
class Dialer;
}

class Dialer : public QWidget
{
    Q_OBJECT

public:
    explicit Dialer(QWidget *parent = 0, Serial *serial = 0);
    ~Dialer();

private:
    QString numberToCall;
    Ui::Dialer *ui;
    void createConnections();
    //void makeCall();
    Serial *serial;
private slots:
    void onButtonClicked();
};

#endif // DIALER_H
