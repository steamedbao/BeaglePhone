#include "texthome.h"
#include "ui_texthome.h"

TextHome::TextHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextHome)
{
    ui->setupUi(this);
}

TextHome::~TextHome()
{
    delete ui;
}
