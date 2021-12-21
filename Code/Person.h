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
    Account _acc;
public:
    Person();
    Person(QString id, QString name, bool gender, QString address, QString username, QString password);
    QString toString();
    QString showID();

    bool checkIsUsername(QString username);
    bool checkIsID(QString id);

    QString showName();
    QString showGender();
    QString showAddress();

    void editID(QString newID);
    void editName(QString newName);
    void editGender(bool Gender);
};

#endif // PERSON_H
