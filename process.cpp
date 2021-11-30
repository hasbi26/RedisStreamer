#include "process.h"

// token github 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

Process::Process(QObject *parent) : QObject(parent)
{
    mserial = new QSerialPort(this);

    //mserial->setPortName("/dev/pts/3");
    mserial->setPortName("/dev/ttyACM0");
    mserial->setBaudRate(QSerialPort::Baud19200);
    mserial->setDataBits(QSerialPort::Data8);
    mserial->setParity(QSerialPort::NoParity);
    mserial->setStopBits(QSerialPort::OneStop);
    mserial->setFlowControl(QSerialPort::NoFlowControl);

    if (mserial->open(QIODevice::ReadWrite)){
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(MytimerSlot()));
        //msec
        timer->start(1000);
        redisClient = new Redis("tcp://127.0.0.1");
        qDebug()<<"terhubung";

    } else {
        qDebug()<< "error Serial" <<mserial->errorString() ;
    }

}


void Process::MytimerSlot(){

    QString test = QString::fromStdString(redisClient->hget("test", "status").value());

    qDebug ()<<"testt " << test.toLatin1();
    mserial->write(test.toLatin1());

}
