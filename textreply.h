#ifndef TEXTREPLY_H
#define TEXTREPLY_H

#include "page.h"

namespace Ui {
class TextReply;
}

class TextReply : public Page
{
    Q_OBJECT

public:
    explicit TextReply(QWidget *parent = 0);
    ~TextReply();

private:
    Ui::TextReply *ui;
};

#endif // TEXTREPLY_H
