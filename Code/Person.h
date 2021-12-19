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
public:
    static LibraryDatabase LibData;
private:
    QString _id;
    QString _name;
    QString _gender;
    QString _address;
    Account _acc;
public:
    Person();
    Person(QString id, QString name, QString gender, QString address, QString username, QString password);
    QString showInfor();
    QString showID();

    QString showName();
    QString showGender();
    QString showAddress();

    void editID(QString newID);
    void editName(QString newName);
    void editGender(QString Gender);

};

#endif // PERSON_H
