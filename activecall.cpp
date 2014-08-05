#include "activecall.h"
#include "ui_activecall.h"
#include <QMessageBox>
#include <iostream>

ActiveCall::ActiveCall(QWidget *parent) :
    Page(parent),
    resetCount(false), ui(new Ui::ActiveCall)
{
    ui->setupUi(this);
    callTimer = new QTimer(this);
    callTimer->setInterval(1000);
    seconds = 0;
    minutes = 0;
    createConnections();
}
void ActiveCall::createConnections()
{
    connect(ui->endCallButton, SIGNAL(clicked()), this, SLOT(endCall()));
    connect(callTimer, SIGNAL(timeout()), this, SLOT(tick()));
    connect(serialPort, SIGNAL(hangUp()), this, SLOT(endCall()));
    connect(serialPort, SIGNAL(incomingCall(QString)), this, SLOT(answerCall(QString)));
}
void ActiveCall::endCall()
{
    serialPort->endCall();
    callTimer->stop();
    resetCount = true;

    emit closeDialer();
}
void ActiveCall::tick()
{
    if (!resetCount)
    {
        if(seconds < 60)
        {
            seconds++;
        }
        else if (seconds == 60)
        {
            minutes++;
            seconds = 0;
        }
    }
    else if (resetCount)
    {
       minutes = 0;
       seconds = 0;
       resetCount = false;
    }
    ui->activeTimeLabel->setText(QString::number(minutes) + ":" + QString::number(seconds));

}

ActiveCall::~ActiveCall()
{
    delete ui;
    delete callTimer;
}
void ActiveCall::updateNumber(QString number)
{
    ui->activeNumberLabel->setText(number);
}
void ActiveCall::answerCall(QString number)
{
    std::cout << "inside answer" << std::endl;
    QMessageBox msgBox;
    msgBox.setModal(true);
    msgBox.setText(QString("Incoming Call From : ") + number);
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Ignore);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Ok)
    {
        emit answer();
        updateNumber(number);
    }
}
