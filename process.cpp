#include "process.h"

Process::Process(QObject *parent) : QObject(parent)
{

    qDebug()<<"test";

    redisClient = new Redis("tcp://127.0.0.1");

    qDebug ()<< redisClient;


   auto test = redisClient->hget("status", "start");

   qDebug ()<<"testt ";test;


}
