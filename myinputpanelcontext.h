#ifndef MYINPUTPANELCONTEXT_H
 #define MYINPUTPANELCONTEXT_H

 #include <QtGui/QInputContext>

 #include "myinputpanel.h"

 class MyInputPanel;


 class MyInputPanelContext : public QInputContext
 {
     Q_OBJECT

 public:
     MyInputPanelContext();
     ~MyInputPanelContext();

     bool filterEvent(const QEvent* event);

     QString identifierName();
     QString language();

     bool isComposing() const;

     void reset();

 private slots:
     void sendCharacter(QChar character);
     void sendKey(int key);

 private:
     void updatePosition();

 private:
     MyInputPanel *inputPanel;
 };


 #endif // MYINPUTPANELCONTEXT_H
