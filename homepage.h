#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "page.h"

namespace Ui {
class HomePage;
}

class HomePage : public Page
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();
    void createConnections();

signals:
    void phoneButtonPressed();
    void textButtonPressed();

private:
    Ui::HomePage *ui;

private slots:
    void phoneClicked();
    void textClicked();

};

#endif // HOMEPAGE_H
