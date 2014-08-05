#include "texthome.h"
#include "ui_texthome.h"

TextHome::TextHome(QWidget *parent) :
    Page(parent),
    ui(new Ui::TextHome)
{
    ui->setupUi(this);
    createConnections();
}
void TextHome::createConnections()
{
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(createNewText()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(messageList()));

}

TextHome::~TextHome()
{
    delete ui;
}
