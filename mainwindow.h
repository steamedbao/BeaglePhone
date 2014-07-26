#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class Dialer;
class HomePage;
class TextThread;
class TextHome;
class Power;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialer *dialer;
    HomePage *homePage;
    TextThread *textThread;
    TextHome *textHome;
    Power *power;
    int currentIndex;
    int previousIndex;


    void createConnections();

private slots:
    void goToPhone();
    void goToText();
    void goToHome();
    void goToPower();
    void goToPrevious();
};

#endif // MAINWINDOW_H
