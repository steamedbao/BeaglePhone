#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "homepage.h"
#include "dialer.h"
#include "textthread.h"
#include "texthome.h"
#include "power.h"

#define HOME_INDEX 0
#define PHONE_INDEX 1
#define TEXT_HOME_INDEX 2
#define POWER_INDEX 3

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new Serial(this);
    homePage = new HomePage(this);
    dialer = new Dialer(this, serial);
    textHome = new TextHome(this);
    power = new Power (this);
    ui->stackedWidget->addWidget(homePage);
    ui->stackedWidget->addWidget(dialer);
    ui->stackedWidget->addWidget(textHome);
    ui->stackedWidget->addWidget(power);
    ui->stackedWidget->setCurrentIndex(0);
    createConnections();
    QTimer::singleShot(1000, this, SLOT(showFullScreen()));



}
void MainWindow::createConnections()
{
    connect(homePage, SIGNAL(phoneButtonPressed()), this, SLOT(goToPhone()));
    connect(homePage, SIGNAL(textButtonPressed()), this, SLOT(goToText()));
    connect(ui->actionHome, SIGNAL(triggered()), this, SLOT(goToHome()));
    connect(ui->actionPower, SIGNAL(triggered()), this, SLOT(goToPower()));
    connect(power, SIGNAL(goBack()), this , SLOT(goToPrevious()));
}
void MainWindow::goToHome()
{
    previousIndex = currentIndex;
    currentIndex = HOME_INDEX;
    ui->stackedWidget->setCurrentIndex(HOME_INDEX);
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
Serial* MainWindow::getSerial()
{
    return serial;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete homePage;
    delete dialer;
    delete textHome;
    delete power;
}
