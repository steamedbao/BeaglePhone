#include "serial.h"
#include <iostream>
#include <QStringList>
#include <QRegExp>
#ifdef __linux__
#define SERIAL_PORT "/dev/ttyO4"
#endif


Serial::Serial(QObject *parent) : QObject(parent), messageString("")
{
    //Initialize Serial comms at 9600 8N1
    serialPort = new QextSerialPort(SERIAL_PORT, QextSerialPort::EventDriven, this);
    serialPort->setBaudRate(BAUD9600);
    serialPort->setDataBits(DATA_8);
    serialPort->setFlowControl(FLOW_OFF);
    serialPort->setParity(PAR_NONE);
    serialPort->setStopBits(STOP_1);
    serialPort->open(QIODevice::ReadWrite);
    connectTimer = new QTimer(this);
    connectTimer->setInterval(50000);
    connectTimer->start();
    createConnections();
}
void Serial::createConnections()
{
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(onDataAvailable()));
    connect(connectTimer, SIGNAL(timeout()), this, SLOT(onConnectionTimeout()));
}
void Serial::onDataAvailable()
{
    QByteArray message = serialPort->readAll();
    QString incomingMessage(message);
    messageString.append(message);
    if(messageString.contains("\n"))
    {
        QStringList messagePool = messageString.split(QRegExp("[/r/n]"));
        for(int i = 0; i < messagePool.size(); i++)
        {
            if (messagePool[i].contains("NO CARRIER"))
            {
                std::cerr << "No Carrier" << std::endl;
                clearToCall = false;
            }
            if(messagePool[i].contains("CME ERROR: 4"))
            {
                std::cout << "Carrier Error, retry" << std::endl;
            }
            if(messagePool[i].contains("SIND: 2"))
                std::cout << "Dialing" << std::endl;
        }
        messageString = "";
    }


    std::cout << incomingMessage.toStdString();
    if(incomingMessage.contains("\n"))
        std::cout << std::endl;
}
void Serial::makeCall(QString const message)
{
    QString dataString = message;
    dataString.remove("-", Qt::CaseSensitive);
    dataString.remove("(", Qt::CaseSensitive);
    dataString.remove(")", Qt::CaseSensitive);
    dataString.prepend("ATD");
    dataString.append("\r\n");
    QByteArray ba =dataString.toAscii();
    if(serialPort->isOpen())
    {
        std::cout << "Serial Port Open" << std::endl;
        std::cout << dataString.toStdString() << std::endl;
        int ret = serialPort->write(ba);
        std::cout << QString::number(ret).toStdString() << std::endl;
    }
    else
    {
        std::cerr << "Serial Port is closed, permissions problem?" << std::endl;
    }
}

void Serial::onConnectionTimeout()
{

}

QextSerialPort* Serial::getSerialPort()
{
    return this->serialPort;
}
Serial::~Serial()
{
    connectTimer->stop();
    serialPort->close();
}

