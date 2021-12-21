#include"Person.h"

Person::Person(){
    this->_id = "unknown";
    this->_name ="unknown";
    this->_gender="unknown";
    this->_address="unknown";
    Account temp("unknown", "unknown");
    this->_acc=temp;
}

Person::Person(QString id, QString name, bool gender, QString address, QString username, QString password){
    this->_id = id;
    this->_name =name;
    this->_gender=gender;
    this->_address=address;
    Account temp(username, password);
    this->_acc = temp;
}

QString Person::toString(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    out<<this->_id<<"|";
    out<<this->_name<<"|";
    out<<this->_gender<<"|";
    out<<this->_address<<"|";
    out<<this->_acc.toString();

    QString res=out.readAll();
    return res;
}

bool Person::checkIsUsername(QString username){
    return this->_acc.checkIsUserName(username);
}

bool Person::checkIsID(QString id){
    return this->_id == id;
}

QString Person::showName(){
    return this->_name;
}

QString Person:: showGender(){
    if (this->_gender==0) return "Male";
    return "Female";
}

QString Person:: showAddress(){
    return this->_address;
}

void Person::editID(QString newID){
    this->_id=newID;
}

void Person::editName(QString newName){
    this->_name=newName;
}

void Person::editGender(bool Gender){
    this->_gender=Gender;
}
