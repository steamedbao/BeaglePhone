#ifndef SERIAL_H
#define SERIAL_H
#include <QObject>
#include <QTimer>
#include "qextserialport.h"

class Serial : public QObject
{
    Q_OBJECT
public:
    Serial(QObject *parent=0);
    void createConnections();
    QextSerialPort* getSerialPort();
    ~Serial();
    bool clearToCall;
    void makeCall(const QString message);
    void endCall();
    void sendText(QString const number, QString const message);
    int getSignalStrength(){return signalStrength;}
    bool getServiceActive(){return serviceActive;}
    bool getMute(){return mute;}
    bool getRecieveMessages(){return recieveMessages;}

    bool getSmsFull(){return smsFull;}
signals:
    void hangUp();
    void incomingCall(QString);

private:
    QextSerialPort *serialPort;
    QString messageString;
    QTimer *connectTimer;
    int signalStrength;
    bool serviceActive;
    bool mute;
    bool recieveMessages;
    bool smsFull;
private slots:
    void onDataAvailable();
    void getSimStatus();
};

#endif // SERIAL_H
