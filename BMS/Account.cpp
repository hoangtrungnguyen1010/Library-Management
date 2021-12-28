#include"Account.h"

Account::Account(){
    this->_password="unknown";
    this->_username="unknown";
}
Account::Account(QString username, QString password){
    this->_username = username;
    this->_password = password;
}

void Account::changePassWord(QString newPassWord){
    this->_password=newPassWord;
}

QString Account::toString() const{
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);
    out<<this->_username<<"|";
    out<<this->_password;
    QString res=out.readAll();
    return res;
}

bool Account::checkIsUserName(QString name){
    return this->_username==name;
}
bool Account::checkIsPassword(QString pass)
{
    return this->_password==pass;
}
