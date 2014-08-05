#ifndef TEXTHOME_H
#define TEXTHOME_H

#include "page.h"

namespace Ui {
class TextHome;
}

class TextHome : public Page
{
    Q_OBJECT

public:
    explicit TextHome(QWidget *parent = 0);
    void createConnections();
    ~TextHome();

private:
    Ui::TextHome *ui;
private slots:
    void messageList() { emit messageListPress();}
    void createNewText() { emit newTextButtonPress();}
signals:
    void newTextButtonPress();
    void messageListPress();
};

#endif // TEXTHOME_H
