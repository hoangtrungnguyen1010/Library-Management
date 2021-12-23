#include"Admin.h"

Admin::Admin(QString id, QString name, bool gender, QString address, QString account, QString password):Person(id,name, gender,address,account,password){

}

QString Admin::toString(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);
    out<<Person::toString();
    out<<"|Admin";
    QString res=out.readAll();
    return res;
}

//void Admin::viewBorrowedBook(){

//}

//void Admin::viewDamagedBook(){

//}

//void Admin::addBook(Book addedBook, int num){

//}

//void Admin::deleteBook(Book delBook, int num){

//}
