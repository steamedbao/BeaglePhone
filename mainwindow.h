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
class Page;
class Settings;
class ActiveCall;
class TextReply;
class MyInputPanelContext;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, MyInputPanelContext *ic = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    Page *page;
    Dialer *dialer;
    HomePage *homePage;
    TextThread *textThread;
    TextHome *textHome;
    Power *power;
    Settings *settings;
    ActiveCall *activeCall;
    TextReply* textReply;


    int currentIndex;
    int previousIndex;


    void createConnections();

private slots:
    void goToPhone();
    void goToText();
    void goToHome();
    void goToPower();
    void goToPrevious();
    void goToSettings();
    void goToActiveCall();
    void endActiveCall();
    void goToMessageList();
    void goToNewMessage();



};

#endif // MAINWINDOW_H
