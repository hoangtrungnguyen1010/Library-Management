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
protected:
    static HumanDatabase* _HumanDTB;
private:
    QVector<User*> UserData;
    QVector<Admin> AdData;
    QString _fileName=":/Data/Resource/Data/UserData.txt";
public:
    HumanDatabase(){};
    HumanDatabase(const HumanDatabase  &other) = delete;
    void operator=(const HumanDatabase &) = delete;
    static HumanDatabase *GetInstance(){
        if (!_HumanDTB){
            _HumanDTB= new HumanDatabase();
        }
        RealLibraryDatabase* lib = RealLibraryDatabase::GetInstance();
        _HumanDTB->loadDTB(lib);
        return _HumanDTB;
    }
    bool addNewUser(QString id, QString name, bool gender, QString address, QString username, QString password, QString type);
    bool addNewAdmin(QString id, QString name, bool gender, QString address, QString username, QString password);
    void loadDTB(RealLibraryDatabase* Lib);
    void printDTB(); //for debugging
    void saveDTB();
    User* getUser(QString username, QString password);
    ~HumanDatabase();


};

#endif // HUMANDATABASE_H
