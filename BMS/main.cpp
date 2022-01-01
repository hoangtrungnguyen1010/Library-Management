#include<QVector>
#include<QDebug>
#include<QDateTime>
#include <QApplication>
#include"HumanDatabase.h"
#include"LibraryDatabase.h"
#include"RealLibraryDatabase.h"
#include "mainwindow.h"
#include "loginpage.h"
#include <QFile>
#include <QIODevice>

User* login_user=nullptr;
Admin* login_admin=nullptr;


HumanDatabase* HumanDatabase::Instance=nullptr;
RealLibraryDatabase* RealLibraryDatabase::Instance=nullptr;


int main(int argc, char *argv[])
{
    RealLibraryDatabase* Lib=RealLibraryDatabase::getInstance();
    HumanDatabase* Human=HumanDatabase::getInstance();
    QApplication a(argc, argv);
    LoginPage_2 b;
    MainWindow m;


    b.show();

       return a.exec();
//        login_user=Human->UserData[3];
//        login_user->borrowBook(&Lib->getListBook()[4]);
//        login_user->borrowBook(&Lib->getListBook()[5]);
//        login_user->borrowBook(&Lib->getListBook()[0]);

//        login_user->borrowBook(&Lib->getListBook()[1]);

//    delete Lib;
//    delete Human;

}
