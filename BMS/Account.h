#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<QString>
#include<QTextStream>
#include <QIODevice>

using namespace std;
class Account{
private:
    QString _username;
    QString _password;
public:
    Account();
    Account(QString username, QString password);
    void changePassWord(QString newPassWord);
    QString toString() const;
    bool checkIsUserName(QString name);
    bool checkIsPassword(QString pass);

    QString showUsername();
    QString showPass();

    void editPass(QString newPass);
};

#endif // ACCOUNT_H
