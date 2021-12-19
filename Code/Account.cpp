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
