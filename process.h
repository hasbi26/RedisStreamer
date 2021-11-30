#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include <QDebug>
#include <redis++.h>

class Process : public QObject
{
    Q_OBJECT
public:
    explicit Process(QObject *parent = nullptr);

signals:

private:
    Redis *redisClient;

};

#endif // PROCESS_H
