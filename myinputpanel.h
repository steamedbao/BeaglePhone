#ifndef MYINPUTPANEL_H
 #define MYINPUTPANEL_H

 #include <QtGui>
 #include <QtCore>

 #include "ui_myinputpanel.h"


 class MyInputPanel : public QWidget
 {
     Q_OBJECT

 public:
     MyInputPanel();

 signals:
     void characterGenerated(QChar character);
     void keyPressed(int key);

 protected:
     bool event(QEvent *e);

 private slots:
     void saveFocusWidget(QWidget *oldFocus, QWidget *newFocus);
     void buttonClicked(QWidget *w);

 private:
     Ui::MyInputPanel form;
     QWidget *lastFocusedWidget;
     QSignalMapper signalMapper;
     bool shiftClick;

     void setKeyboardCaps();
     void setKeyboardLower();
 };


 #endif // MYINPUTPANEL_H
