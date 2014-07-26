#ifndef POWER_H
#define POWER_H

#include <QWidget>

namespace Ui {
class Power;
}

class Power : public QWidget
{
    Q_OBJECT

public:
    explicit Power(QWidget *parent = 0);
    ~Power();
signals:
    void goBack();

private:
    Ui::Power *ui;
    void createConnections();

private slots:
    void shutDownSys();
    void closeApp();
    void goToPrevious();

};

#endif // POWER_H
