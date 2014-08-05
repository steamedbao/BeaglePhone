#include "textthread.h"
#include "ui_textthread.h"

TextThread::TextThread(QWidget *parent) :
    Page(parent),
    ui(new Ui::TextThread)
{
    ui->setupUi(this);
    createConnections();
}
void TextThread::createConnections()
{

}

TextThread::~TextThread()
{
    delete ui;
}
