#include "process.h"
#include "QThread"

// token github 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
// new token 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

Process::Process(QObject *parent) : QObject(parent)
{
    mserial = new QSerialPort(this);
    redisClient = new Redis("tcp://127.0.0.1");
    redisClient->hset("test", "status", "0");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MytimerSlot()));
    timer->start(1000);

}


void Process::MytimerSlot(){

    qDebug()<<"timer check redis ";
    QString test = QString::fromStdString(redisClient->hget("test", "status").value());
    if (test == "1"){

      //mserial->setPortName("/dev/pts/3");
        mserial->setPortName("/dev/ttyqu");
        mserial->setBaudRate(QSerialPort::Baud19200);
        mserial->setDataBits(QSerialPort::Data8);
        mserial->setParity(QSerialPort::NoParity);
        mserial->setStopBits(QSerialPort::OneStop);
        mserial->setFlowControl(QSerialPort::NoFlowControl);

        if (mserial->open(QIODevice::ReadWrite)){
            sendInterval = new QTimer(this);
            connect(sendInterval, SIGNAL(timeout()), this, SLOT(timerInterval()));
            sendInterval->start(1000);
        } else {
            qDebug() <<mserial->errorString() ;
        }
    }
}

void Process::setOfftimer(){

    sendInterval->stop();
    redisClient->hset("test", "status", "0");
    qDebug ()<<"set to 0 OFF";
    mserial->close();
    timer->start(1000);

}



void Process::timerInterval(){

    timer->stop();
    static int time = 0;
    time++; // decrement counter
    if (time==7) // countdown has finished
    {
        QTimer::singleShot(100, this, SLOT(setOfftimer()));
        time = 0;
        qDebug()<<"redis" <<"o =";
    }
    else // re-start counter
    {
        qDebug()<<"water ngochor =" << time;
        QString test = QString::fromStdString(redisClient->hget("test", "status").value());
        mserial->write(test.toLatin1()+"\n");
    }

}


