#include "textreply.h"
#include "ui_textreply.h"

TextReply::TextReply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextReply)
{
    ui->setupUi(this);
}

TextReply::~TextReply()
{
    delete ui;
}
