#include "serial.h"
#include <iostream>
#include <QStringList>
#include <QRegExp>
#ifdef __linux__
#define SERIAL_PORT "/dev/ttyO4"
#endif


Serial::Serial(QObject *parent) : QObject(parent), messageString(""), signalStrength(0), serviceActive(false), mute(false),
    recieveMessages(false), smsFull(false)
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
    connectTimer->setInterval(100000);
    //connectTimer->start();
    createConnections();
}
void Serial::createConnections()
{
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(onDataAvailable()));
    //connect(connectTimer, SIGNAL(timeout()), this, SLOT(getSimStatus()));
}
void Serial::onDataAvailable()
{
    QByteArray message = serialPort->readAll();
    QString incomingMessage(message);
    messageString.append(message);
    if(messageString.contains("\n") || messageString.contains("\r"))
    {
        QStringList messagePool = messageString.split(QRegExp("[/r/n]"));
        for(int i = 0; i < messagePool.size(); i++)
        {
            if(messagePool[i].contains("CME ERROR: 4"))
            {
                std::cout << "Operation Not Supported" << std::endl;
            }
            if(messagePool[i].contains("CIND:"))
            {
                QString tempString = messagePool[i];
                tempString.remove("+CIND: ", Qt::CaseSensitive);
                QStringList statusData = tempString.split(",");
                if(statusData.size() == 8)
                {
                    signalStrength = statusData[1].toInt();
                    serviceActive = (statusData[2] == QString("1"));
                    mute = (statusData[3] == QString("1"));
                    recieveMessages = (statusData[4] == QString("1"));
                    smsFull = (statusData[7] == QString("1"));
                }

            }
            if(messagePool[i].contains("SIND: 6,1") || messagePool[i].contains ("NO CARRIER"))
            {
                emit hangUp();
            }
            if(messagePool[i].contains("CLIP:"))
            {
                QString tempString = messagePool[i];
                tempString.remove("+CLIP: ", Qt::CaseSensitive);
                QStringList callInfo = tempString.split(",");
                QString number = callInfo[0].section("", 0,9);
                number.insert(0,"(");
                number.insert(4,")");
                emit incomingCall(number);
                std::cout << "Incoming Call" << std::endl;

            }
            if(messagePool[i].contains("SIND: 2"))
            {
                std::cout << "Dialing" << std::endl;

            }
            if(messagePool[i].contains("RING"))
            {
                emit incomingCall(QString("Unknown"));

                std::cout << "Incoming Call" << std::endl;
            }
            if(messagePool[i].contains("SIND: 2"))
            {
                std::cout << "Dialing" << std::endl;

            }

        }
        messageString = "";
    }

    if(!incomingMessage.contains("OK", Qt::CaseSensitive) && !incomingMessage.contains("CIND", Qt::CaseSensitive))
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
void Serial::sendText(QString const number, QString const message)
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
    emit hangUp();
}
void Serial::endCall()
{
    QString dataString;
    dataString.append("ATH");
    dataString.append("\r\n");
    QByteArray ba =dataString.toAscii();
    if(serialPort->isOpen())
    {
        std::cout << "Hangup Sequence Begun" << std::endl;
        std::cout << dataString.toStdString() << std::endl;
        int ret = serialPort->write(ba);
        std::cout << QString::number(ret).toStdString() << std::endl;
    }
    else
    {
        std::cerr << "Serial Port is closed, permissions problem?" << std::endl;
    }
}

void Serial::getSimStatus()
{
    QString dataString("AT+CIND?\r\n");
    QByteArray ba =dataString.toAscii();
    if(serialPort->isOpen())
    {
        serialPort->write(ba);
    }
    else
    {
        std::cerr << "Serial Port is closed, permissions problem?" << std::endl;
    }
}

QextSerialPort* Serial::getSerialPort()
{
    return this->serialPort;
}
Serial::~Serial()
{
    connectTimer->stop();
    delete connectTimer;
    serialPort->close();
    delete serialPort;
}

