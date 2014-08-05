#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    debug = new QDebugStream(std::cout, ui->textEdit);
}

Settings::~Settings()
{
    delete ui;
    delete debug;
}
