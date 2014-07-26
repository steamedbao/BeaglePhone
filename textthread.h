#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QWidget>

namespace Ui {
class TextThread;
}

class TextThread : public QWidget
{
    Q_OBJECT

public:
    explicit TextThread(QWidget *parent = 0);
    ~TextThread();

private:
    Ui::TextThread *ui;
};

#endif // TEXTTHREAD_H
