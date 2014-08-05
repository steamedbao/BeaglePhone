#ifndef ACTIVECALL_H
#define ACTIVECALL_H

#include <QWidget>
#include "page.h"
#include <QTimer>

namespace Ui {
class ActiveCall;
}

class ActiveCall : public Page
{
    Q_OBJECT

public:
    explicit ActiveCall(QWidget *parent = 0);
    ~ActiveCall();
    void createConnections();
    QTimer* getTimer() {return callTimer;}
    bool resetCount;

public slots:
    void updateNumber(QString number);
    void endCall();
    void tick();
    void answerCall(QString number);
signals:
    void closeDialer();
    void answer();

private:
    Ui::ActiveCall *ui;
    QTimer *callTimer;
    int seconds;
    int minutes;

};

#endif // ACTIVECALL_H
