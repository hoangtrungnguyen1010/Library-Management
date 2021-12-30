#include<QVector>
#include<QDebug>
#include<QDateTime>
#include <QApplication>
#include"HumanDatabase.h"
#include"LibraryDatabase.h"
#include"RealLibraryDatabase.h"
#include "mainwindow.h"
#include "loginpage.h"


User* login_user;
HumanDatabase* HumanDatabase::Instance=nullptr;
RealLibraryDatabase* RealLibraryDatabase::Instance=nullptr;


int main(int argc, char *argv[])
{

    RealLibraryDatabase* Lib=RealLibraryDatabase::getInstance();
    HumanDatabase* Human=HumanDatabase::getInstance();
    QApplication a(argc, argv);
    LoginPage_2 b;
    b.show();
    return a.exec();
    //debugging for searching
//    QVector<Book> res;
//    res = Lib->findBookByName("science");

//    for(auto i : res){
//        qDebug()<<i.getName();
//    }
}
