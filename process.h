#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include <QDebug>
#include <redis++.h>
#include <QTimer>
 #include <QSerialPort>

class Process : public QObject
{
    Q_OBJECT
public:
    explicit Process(QObject *parent = nullptr);
    QTimer *timer;
    QTimer *sendInterval;
    QSerialPort *mserial;
    int flag = 1;

public slots :
    void MytimerSlot();
    void setOfftimer();
    void timerInterval();



signals:

private:
    Redis *redisClient;


};

#endif // PROCESS_H
