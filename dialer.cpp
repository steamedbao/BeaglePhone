#include "dialer.h"
#include "ui_dialer.h"
#include <QList>

Dialer::Dialer(QWidget *parent) :
    QWidget(parent), numberToCall(""),
    ui(new Ui::Dialer)
{
    ui->setupUi(this);
    createConnections();
}

void Dialer::createConnections()
{
    QList<QPushButton *> pushButtons = this->findChildren<QPushButton*>();
    for(int i = 0; i <pushButtons.size(); i++)
    {
        connect(pushButtons[i], SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    }
}
void Dialer::onButtonClicked()
{
    QObject *caller = QObject::sender();
    QPushButton *callerPushButton = qobject_cast<QPushButton *>(caller);
    if("phoneButton" != caller->objectName() && "backSpaceButton" != caller->objectName())
    {
        if(3 == numberToCall.size() || 9 == numberToCall.size())
        {
            if(3 == numberToCall.size())
            {
                numberToCall.prepend("(");
                numberToCall.append(")");
            }
            numberToCall.append("-");
            numberToCall.append(callerPushButton->text());
        }
        else if (0 == numberToCall.size())
            numberToCall = callerPushButton->text();
        else
            numberToCall.append(callerPushButton->text());
    }
    else if ("phoneButton" == caller->objectName() || "backSpaceButton" == caller->objectName())
    {
       if("phoneButton" == caller->objectName())
           makeCall();
       else if("backSpaceButton" == caller->objectName())
           numberToCall.chop(1);
    }
    ui->lineEdit->setText(numberToCall);
}
void Dialer::makeCall()
{

}

Dialer::~Dialer()
{
    delete ui;
}
