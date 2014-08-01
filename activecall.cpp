#include "activecall.h"
#include "ui_activecall.h"

ActiveCall::ActiveCall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActiveCall)
{
    ui->setupUi(this);
}

ActiveCall::~ActiveCall()
{
    delete ui;
}
