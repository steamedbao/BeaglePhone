#ifndef ACTIVECALL_H
#define ACTIVECALL_H

#include <QWidget>

namespace Ui {
class ActiveCall;
}

class ActiveCall : public QWidget
{
    Q_OBJECT

public:
    explicit ActiveCall(QWidget *parent = 0);
    ~ActiveCall();

private:
    Ui::ActiveCall *ui;
};

#endif // ACTIVECALL_H
