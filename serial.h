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

private:
    QextSerialPort *serialPort;
    QString messageString;
    QTimer *connectTimer;
private slots:
    void onDataAvailable();
    void onConnectionTimeout();
};

#endif // SERIAL_H
