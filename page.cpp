#include "page.h"

Page::Page(QWidget *parent, MyInputPanelContext *ic) : QWidget(parent)
{
    serialPort = new Serial(this);
    inputPanel = ic;
}
Page::~Page()
{
    delete serialPort;
    delete inputPanel;
}
