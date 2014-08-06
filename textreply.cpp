#include "textreply.h"
#include "ui_textreply.h"

TextReply::TextReply(QWidget *parent) :
    Page(parent),
    ui(new Ui::TextReply)
{
    ui->setupUi(this);

}

TextReply::~TextReply()
{
    delete ui;
}
