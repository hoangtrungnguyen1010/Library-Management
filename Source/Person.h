#pragma once
#ifndef PERSON_H
#define PERSON_H
#include<QString>
#include<sstream>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include "LibraryDatabase.h"
#include<QDateTime>
#include"Account.h"

using namespace std;

class Person{
private:
    QString _id;
    QString _name;
    bool _gender; //0 : male, 1: female
    QString _address;
    QString _type;
    Account _acc;
public:
    Person();
    virtual ~Person(){};
    Person(QString id, QString name, bool gender, QString address, QString username, QString password);
    QString toString();


    bool checkIsUsername(QString username);
    bool checkIsPassword(QString pass);
    bool checkIsID(QString id);

    QString showID();
    QString showName();
    QString showGender();
    QString showAddress();
    QString showType();
    QString showUsername();
    QString showPass();

    void editName(QString newName);
    void editGender(bool Gender);
    void editAddress(QString newAddress);
    void editPass(QString newPass);
};

#endif // PERSON_H
