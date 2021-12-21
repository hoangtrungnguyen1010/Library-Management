#include<QVector>
#include<QDebug>
#include<QDateTime>
#include"HumanDatabase.h"
#include"LibraryDatabase.h"
#include"RealLibraryDatabase.h"
int main(int argc, char *argv[])
{
    RealLibraryDatabase Lib;
    Lib.uploadBook();
    HumanDatabase Human;
    Human.loadDTB(Lib);
    qDebug()<<Human.addNewUser("20120609", "sdfsd", 1, "wefsdf", "sdfsdf", "sdfsdf", "Vip User");

    Human.printDTB();
    Human.saveDTB();
    Lib.sortByID();
    Lib.saveDTB();


//    qDebug()<<Lib.viewListBook();
//    qDebug()<<"-------------------------sorted---------------------------------------";

//    Lib.sortByName();
//    qDebug()<<"-------------------------sorted---------------------------------------";

//    qDebug()<<Lib.viewListBook();


//   QDateTime dateTime(QDateTime::fromString("15:56:44 20-12-2021", "hh:mm:ss dd-MM-yyyy"));
//   QString sDatetime = dateTime.toString("hh:mm:ss dd-MM-yyyy");
//   qDebug()<<"hh:mm:ss dd-MM-yyyy";
}
