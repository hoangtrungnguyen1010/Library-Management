#include<QVector>
#include<QDebug>
#include<QDateTime>
#include <QApplication>
#include"HumanDatabase.h"
#include"LibraryDatabase.h"
#include"RealLibraryDatabase.h"
#include "mainwindow.h"
#include "loginpage.h"
Person p;
RealLibraryDatabase* RealLibraryDatabase:: _LibDTB;
HumanDatabase* HumanDatabase:: _HumanDTB;

int main(int argc, char *argv[])
{
    RealLibraryDatabase* Lib= RealLibraryDatabase::GetInstance();
    HumanDatabase* Human = HumanDatabase::GetInstance();
    qDebug()<<Human->addNewUser("20120609", "sdfsd", 1, "wefsdf", "sdfsdf", "sdfsdf", "Vip User");

    Lib->sortByID();
    QApplication a(argc, argv);
    LoginPage_2 b(nullptr, Human);
    b.show();
   //    QDialog b;
   //    b.show();
       return a.exec();

//    qDebug()<<Lib.viewListBook();
//    qDebug()<<"-------------------------sorted---------------------------------------";

//    Lib.sortByName();
//    qDebug()<<"-------------------------sorted---------------------------------------";

//    qDebug()<<Lib.viewListBook();


//   QDateTime dateTime(QDateTime::fromString("15:56:44 20-12-2021", "hh:mm:ss dd-MM-yyyy"));
//   QString sDatetime = dateTime.toString("hh:mm:ss dd-MM-yyyy");
//   qDebug()<<"hh:mm:ss dd-MM-yyyy";
}
