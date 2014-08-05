#ifndef TEXTREPLY_H
#define TEXTREPLY_H

#include <QWidget>

namespace Ui {
class TextReply;
}

class TextReply : public QWidget
{
    Q_OBJECT

public:
    explicit TextReply(QWidget *parent = 0);
    ~TextReply();

private:
    Ui::TextReply *ui;
};

#endif // TEXTREPLY_H
