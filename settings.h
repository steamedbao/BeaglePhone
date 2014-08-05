#ifndef SETTINGS_H
#define SETTINGS_H
#include "qdebugstream.h"

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private:
    Ui::Settings *ui;
    QDebugStream *debug;
};

#endif // SETTINGS_H
