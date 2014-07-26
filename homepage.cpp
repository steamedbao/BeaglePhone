#include "homepage.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    connect(ui->pushButton_phone, SIGNAL(clicked()), this, SLOT(phoneClicked()));
    connect(ui->pushButton_text, SIGNAL(clicked()), this,  SLOT(textClicked()));

}
void HomePage::phoneClicked()
{
    emit phoneButtonPressed();
}
void HomePage::textClicked()
{
    emit textButtonPressed();
}

HomePage::~HomePage()
{
    delete ui;
}
