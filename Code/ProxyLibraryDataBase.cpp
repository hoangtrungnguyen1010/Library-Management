#include"ProxyLibraryDatabase.h"


bool ProxyLibraryDatabase::findBookByName(QString name, Book &res){
    this->_libdata->findBookByName(name, res);
    return 0;
}

bool ProxyLibraryDatabase::findBookByID(QString ID, Book& res){
    this->_libdata->findBookByID(ID, res);
    return 0;
}

void ProxyLibraryDatabase::sortByID(){
    this->_libdata->sortByID();
}

void ProxyLibraryDatabase::sortByName(){
    this->_libdata->sortByName();
}


void ProxyLibraryDatabase::addDamagedBook(QString id, int num){
    if(this->_type == 1) this->_libdata->addDamagedBook(id, num);
}

void ProxyLibraryDatabase::addBook(QString id, QString name, QString author, QString publisher, QString tags, int num){
    if(this->_type == 1) this->_libdata->addBook(id, name, author, publisher, tags, num);
}   //add new kind of book

void ProxyLibraryDatabase::addBook(QString id, int num){
    if(this->_type == 1) this->_libdata->addBook(id, num);
}

void ProxyLibraryDatabase::deleteBook(QString id){
    if(this->_type == 1) this->_libdata->deleteBook(id);
}

void ProxyLibraryDatabase::deleteBook(QString id, int num){
    if(this->_type == 1) this->_libdata->deleteBook(id, num);
}

void ProxyLibraryDatabase::viewBorrowedBook(){

};

void ProxyLibraryDatabase::viewDamagedBook(){};
