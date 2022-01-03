#include"Person.h"

Person::Person(){
    this->_id = "unknown";
    this->_name ="unknown";
    this->_gender="unknown";
    this->_address="unknown";
    Account temp("unknown", "unknown");
    this->_acc=temp;
    this->_type="Admin";
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
bool Person::checkIsPassword(QString pass)
{
    return this->_acc.checkIsPassword(pass);
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
QString Person::showID(){
    return _id;
}
QString Person::showType(){
    return this->_type;
}

QString Person::showUsername(){
    return _acc.showUsername();
}
QString Person::showPass(){
    return _acc.showPass();
}


void Person::editName(QString newName){
    this->_name=newName;
}

void Person::editGender(bool Gender){
    this->_gender=Gender;
}
void Person::editAddress(QString newAddress){
    this->_address=newAddress;
}

void Person::editPass(QString newPass){
    _acc.editPass(newPass);
    qDebug()<<_acc.showPass();
}
