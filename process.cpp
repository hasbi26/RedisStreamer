#include "process.h"

Process::Process(QObject *parent) : QObject(parent)
{

// token github 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

    redisClient = new Redis("tcp://127.0.0.1");

  


   QString test = redisClient->hget("status", "start");

   qDebug ()<<"testt ";test;


}
