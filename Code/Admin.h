#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include"Person.h"
#include"Book.h"

class Admin: public Person{
private:

public:
    Admin(){};
    Admin(QString id, QString name, bool gender, QString address, QString account, QString password);

    QString toString();
};

#endif // ADMIN_H
