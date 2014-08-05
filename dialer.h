#ifndef DIALER_H
#define DIALER_H

#include "page.h"
#include "serial.h"
#include "mainwindow.h"

namespace Ui {
class Dialer;
}

class Dialer : public Page
{
    Q_OBJECT

public:
    explicit Dialer(QWidget *parent = 0);
    void createConnections();
    ~Dialer();
signals:
    void showCall(QString);

private:
    QString numberToCall;
    Ui::Dialer *ui;
private slots:
    void onButtonClicked();
};

#endif // DIALER_H
