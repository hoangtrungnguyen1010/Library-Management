#pragma once
#ifndef HUMANDATABASE_H
#define HUMANDATABASE_H
#include<iostream>
#include<QVector>
#include <QDebug>
#include<QDateTime>
#include <QTextStream>
#include <QDir>
#include"Admin.h"
#include"User.h"
#include"VipUser.h"
#include"RealLibraryDatabase.h"
extern const QDir CURRENT_PATH;
class HumanDatabase{
private:
    static HumanDatabase* Instance;
    public:
    QVector<User*> UserData;
    QVector<Admin> AdData;
    QString _fileName=CURRENT_PATH.relativeFilePath("debug/Resource/Data/UserData.txt");
public:
    static HumanDatabase* getInstance();
     ~HumanDatabase();
public:
    static void init();
    bool addNewUser(QString id, QString name, bool gender, QString address, QString username, QString password, QString type);
    bool addNewAdmin(QString id, QString name, bool gender, QString address, QString username, QString password);
    void loadDTB(RealLibraryDatabase* Lib);
    void printDTB(); //for debugging
    void saveDTB();
    User* findSavedUser(QString username, QString password);
    Admin* findSavedAdmin(QString username, QString password);
    bool checkExisted(QString username);
    QVector<User*> getListUser();

    void editName(QString ID,QString newName);
    void editGender(QString ID,bool Gender);
    void editAddress(QString ID,QString newAddress);
    void editPass(QString ID,QString newPass);

};

#endif // HUMANDATABASE_H
