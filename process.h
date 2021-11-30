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
    QSerialPort *mserial;
public slots :
    void MytimerSlot();



signals:

private:
    Redis *redisClient;


};

#endif // PROCESS_H
