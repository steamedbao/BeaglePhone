#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <iostream>
#include "homepage.h"
#include "dialer.h"
#include "textthread.h"
#include "texthome.h"
#include "power.h"
#include "page.h"
#include "settings.h"
#include "activecall.h"
#include <QWSServer>
#include "textreply.h"

#define HOME_INDEX 0
#define PHONE_INDEX 1
#define TEXT_HOME_INDEX 2
#define POWER_INDEX 3
#define SETTINGS_INDEX 4
#define ACTIVE_CALL_INDEX 5
#define TEXT_MESSAGE_LIST 6
#define TEXT_REPLY 7

MainWindow::MainWindow(QWidget *parent, MyInputPanelContext *ic) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings = new Settings(this);
    page = new Page(this, ic);
    homePage = new HomePage(this);
    dialer = new Dialer(this);
    textHome = new TextHome(this);
    power = new Power (this);
    activeCall = new ActiveCall(this);
    textThread = new TextThread(this);
    textReply = new TextReply(this);

    ui->stackedWidget->addWidget(homePage);
    ui->stackedWidget->addWidget(dialer);
    ui->stackedWidget->addWidget(textHome);
    ui->stackedWidget->addWidget(power);
    ui->stackedWidget->addWidget(settings);
    ui->stackedWidget->addWidget(activeCall);
    ui->stackedWidget->addWidget(textThread);
    ui->stackedWidget->addWidget(textReply);
    ui->stackedWidget->setCurrentIndex(0);
    createConnections();
    QTimer::singleShot(1000, this, SLOT(showFullScreen()));
    QWSServer::instance()->closeMouse();
    QWSServer::instance()->openMouse();


}
void MainWindow::createConnections()
{
    connect(homePage, SIGNAL(phoneButtonPressed()), this, SLOT(goToPhone()));
    connect(homePage, SIGNAL(textButtonPressed()), this, SLOT(goToText()));
    connect(dialer, SIGNAL(showCall(QString)), this, SLOT(goToActiveCall()))  ;
    connect(ui->actionHome, SIGNAL(triggered()), this, SLOT(goToHome()));
    connect(ui->actionPower, SIGNAL(triggered()), this, SLOT(goToPower()));
    connect(ui->actionActiveCall, SIGNAL(triggered()), this, SLOT(goToActiveCall()));
    connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(goToSettings()));
    connect(power, SIGNAL(goBack()), this , SLOT(goToPrevious()));
    connect(activeCall, SIGNAL(closeDialer()), this, SLOT(endActiveCall()));
    connect(activeCall, SIGNAL(answer()), this, SLOT(goToActiveCall()));
    connect(dialer, SIGNAL(showCall(QString)), activeCall, SLOT(updateNumber(QString)));
    connect(textHome, SIGNAL(newTextButtonPress()), this, SLOT(goToNewMessage()));
    connect(textHome, SIGNAL(messageListPress()), this, SLOT(goToMessageList()));
}
void MainWindow::goToHome()
{
    previousIndex = currentIndex;
    currentIndex = HOME_INDEX;
    ui->stackedWidget->setCurrentIndex(HOME_INDEX);
}
void MainWindow::endActiveCall()
{
    ui->actionActiveCall->setEnabled(false);
    goToPrevious();
}

void MainWindow::goToPhone()
{
    previousIndex = currentIndex;
    currentIndex = PHONE_INDEX;
    ui->stackedWidget->setCurrentIndex(PHONE_INDEX);
}
void MainWindow::goToText()
{
    previousIndex = currentIndex;
    currentIndex = TEXT_HOME_INDEX;
    ui->stackedWidget->setCurrentIndex(TEXT_HOME_INDEX);
}
void MainWindow::goToPower()
{
    previousIndex = currentIndex;
    currentIndex = POWER_INDEX;
    ui->stackedWidget->setCurrentIndex(POWER_INDEX);
}
void MainWindow::goToPrevious()
{
    int temp = currentIndex;
    currentIndex = previousIndex;
    previousIndex = temp;
    ui->stackedWidget->setCurrentIndex(currentIndex);

}
void MainWindow::goToSettings()
{
    previousIndex = currentIndex;
    currentIndex = SETTINGS_INDEX;
    ui->stackedWidget->setCurrentIndex(SETTINGS_INDEX);
}
void MainWindow::goToActiveCall()
{
    previousIndex = currentIndex;
    currentIndex = ACTIVE_CALL_INDEX;
    ui->stackedWidget->setCurrentIndex(ACTIVE_CALL_INDEX);
    activeCall->getTimer()->start();
    ui->actionActiveCall->setEnabled(true);

}
void MainWindow::goToMessageList()
{
    previousIndex = currentIndex;
    currentIndex = TEXT_MESSAGE_LIST;
    ui->stackedWidget->setCurrentIndex(TEXT_MESSAGE_LIST);
}
void MainWindow::goToNewMessage()
{
    previousIndex = currentIndex;
    currentIndex = TEXT_REPLY;
    ui->stackedWidget->setCurrentIndex(TEXT_REPLY);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete page;
    delete homePage;
    delete dialer;
    delete textHome;
    delete power;
    delete settings;
}

