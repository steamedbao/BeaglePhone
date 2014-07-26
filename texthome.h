#ifndef TEXTHOME_H
#define TEXTHOME_H

#include <QWidget>

namespace Ui {
class TextHome;
}

class TextHome : public QWidget
{
    Q_OBJECT

public:
    explicit TextHome(QWidget *parent = 0);
    ~TextHome();

private:
    Ui::TextHome *ui;
};

#endif // TEXTHOME_H
