#include "textthread.h"
#include "ui_textthread.h"

TextThread::TextThread(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextThread)
{
    ui->setupUi(this);
}

TextThread::~TextThread()
{
    delete ui;
}
