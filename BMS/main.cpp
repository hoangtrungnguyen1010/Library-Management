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
#include <QDir>
User* login_user;
Admin* login_admin;
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
    delete login_user;
    delete login_admin;
    return a.exec();

}
