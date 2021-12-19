#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<QString>

using namespace std;
class Account{
private:
    QString _username;
    QString _password;
public:
    Account();
    Account(QString username, QString password);
    void changePassWord(QString newPassWord);
};

#endif // ACCOUNT_H
