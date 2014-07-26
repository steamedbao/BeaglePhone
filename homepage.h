#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();

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
