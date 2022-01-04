#include"Admin.h"

Admin::Admin():Person(){
    this->_type="Admin";
}


Admin::Admin(QString id, QString name, bool gender, QString address, QString account, QString password):Person(id,name, gender,address,account,password,"Admin"){

}

Admin::~Admin(){};

QString Admin::toString(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);
    out<<Person::toString();
    out<<"|Admin";
    QString res=out.readAll();
    return res;
}
