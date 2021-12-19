#include"Person.h"

Person::Person(){
    this->_id = "unknown";
    this->_name ="unknown";
    this->_gender="unknown";
    this->_address="unknown";
    Account temp("unknown", "unknown");
    this->_acc=temp;
}

Person::Person(QString id, QString name, QString gender, QString address, QString username, QString password){
    this->_id = id;
    this->_name =name;
    this->_gender=gender;
    this->_address=address;
    Account temp(username, password);
    this->_acc = temp;
}

QString Person::showInfor(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);
    out<<"Full Name: "<<this->_name<<"\n"<<endl;
    out<<"Gender: "<<this->_gender<<"\n"<<endl;
    out<<"Address: "<<this->_address<<"\n"<<endl;
    QString res=out.readAll();
    return res;
}

QString Person::showName(){
    return this->_name;
}

QString Person:: showGender(){
    return this->_gender;
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

void Person::editGender(QString Gender){
    this->_gender=Gender;
}
