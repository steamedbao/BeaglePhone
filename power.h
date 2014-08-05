#ifndef POWER_H
#define POWER_H

#include "page.h"

namespace Ui {
class Power;
}

class Power : public Page
{
    Q_OBJECT

public:
    explicit Power(QWidget *parent = 0);
    void createConnections();
    ~Power();
signals:
    void goBack();

private:
    Ui::Power *ui;

private slots:
    void shutDownSys();
    void closeApp();
    void goToPrevious();

};

#endif // POWER_H
