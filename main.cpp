#include <QCoreApplication>
#include <QDebug>
#include <redis++.h>
#include <process.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Process b;
    return a.exec();
}
