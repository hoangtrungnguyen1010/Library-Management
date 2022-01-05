#include"Person.h"

Person::Person(){
    this->_id = "unknown";
    this->_name ="unknown";
    this->_gender="unknown";
    this->_address="unknown";
    Account* temp=new Account("unknown", "unknown");
    this->_acc=temp;
    this->_type="unknown";
}
Person::~Person()
{
    delete _acc;
}
Person::Person(QString id, QString name, bool gender, QString address, QString username, QString password,QString type){
    this->_id = id;
    this->_name =name;
    this->_gender=gender;
    this->_address=address;
    Account* temp=new Account(username, password);
    this->_acc = temp;
    this->_type=type;
}
Person::Person(const Person& src)
{
    _id=src._id;
    this->_id =src._id;
    this->_name =src._name;
    this->_gender=src._gender;
    this->_address=src._address;
    this->_type=src._type;
    _acc=new Account(src._acc->showUsername(),src._acc->showPass());
}
Person& Person::operator=(const Person& src)
{
    _id=src._id;
    this->_id =src._id;
    this->_name =src._name;
    this->_gender=src._gender;
    this->_address=src._address;
    this->_type=src._type;
    if(_acc)
        delete _acc;
     _acc=new Account(src._acc->showUsername(),src._acc->showPass());
     return *this;
}
QString Person::toString(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    out<<this->_id<<"|";
    out<<this->_name<<"|";
    out<<this->_gender<<"|";
    out<<this->_address<<"|";
    out<<this->_acc->toString();

    QString res=out.readAll();
    return res;
}

bool Person::checkIsUsername(QString username){
    return this->_acc->checkIsUserName(username);
}
bool Person::checkIsPassword(QString pass)
{
    return this->_acc->checkIsPassword(pass);
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
    return _acc->showUsername();
}
QString Person::showPass(){
    return _acc->showPass();
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
    _acc->editPass(newPass);
}
