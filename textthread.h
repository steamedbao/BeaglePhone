#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include "page.h"

namespace Ui {
class TextThread;
}

class TextThread : public Page
{
    Q_OBJECT

public:
    explicit TextThread(QWidget *parent = 0);
    void createConnections();
    ~TextThread();

private:
    Ui::TextThread *ui;
};

#endif // TEXTTHREAD_H
