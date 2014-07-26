#include "power.h"
#include "ui_power.h"
#include <QStringList>
#include <QProcess>

Power::Power(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Power)
{
    ui->setupUi(this);
    createConnections();
}
void Power::createConnections()
{
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(goToPrevious()));
    connect(ui->closeButton, SIGNAL(clicked()), this , SLOT(closeApp()));
    connect(ui->powerButton, SIGNAL(clicked()), this, SLOT(shutDownSys()));
}
void Power::goToPrevious()
{
    emit goBack();
}
void Power::closeApp()
{
    QApplication::quit();
}
void Power::shutDownSys()
{
    QStringList args;
    args << "-h" << "now";
    QProcess::execute("shutdown", args);
    QApplication::quit();
}

Power::~Power()
{
    delete ui;
}
