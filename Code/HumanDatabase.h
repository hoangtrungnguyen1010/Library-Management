#pragma once

#ifndef HUMANDATABASE_H
#define HUMANDATABASE_H
#include<iostream>
#include<QVector>
#include <QDebug>
#include <QTextStream>
#include"Admin.h"
#include"User.h"

class HumanDatabase{
private:
    QVector<User> UserData;
    QVector<Admin> AdData;
    QString fileName="..//Project/Account.txt";

public:
    void loadDTB();
    void printDTB(); //for debugging

};

#endif // HUMANDATABASE_H
