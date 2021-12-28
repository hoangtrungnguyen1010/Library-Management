#pragma once
#ifndef HUMANDATABASE_H
#define HUMANDATABASE_H
#include<iostream>
#include<QVector>
#include <QDebug>
#include<QDateTime>
#include <QTextStream>
#include"Admin.h"
#include"User.h"
#include"VipUser.h"
#include"RealLibraryDatabase.h"

class HumanDatabase{
private:
    static HumanDatabase* Instance;
private:
    QVector<User*> UserData;
    QVector<Admin> AdData;
    QString _fileName=":/Data/Resource/Data/UserData.txt";
public:
    static HumanDatabase* getInstance();
public:
    static void init();
    bool addNewUser(QString id, QString name, bool gender, QString address, QString username, QString password, QString type);
    bool addNewAdmin(QString id, QString name, bool gender, QString address, QString username, QString password);
    void loadDTB(RealLibraryDatabase Lib);
    void printDTB(); //for debugging
    void saveDTB();
    User* findSavedAccount(QString username, QString password);
    ~HumanDatabase();

};

#endif // HUMANDATABASE_H
