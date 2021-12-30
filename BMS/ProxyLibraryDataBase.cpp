#include"ProxyLibraryDatabase.h"


QVector<Book> ProxyLibraryDatabase::findBookByName(QString name){
    return this->_libdata->findBookByName(name);
}

QVector<Book> ProxyLibraryDatabase::findBookByID(QString id){
    return this->_libdata->findBookByID(id);
}

void ProxyLibraryDatabase::sortByID(){
    this->_libdata->sortByID();
}

void ProxyLibraryDatabase::sortByName(){
    this->_libdata->sortByName();
}


void ProxyLibraryDatabase::addDamagedBook(QString id, int num){
    if(this->check()) this->_libdata->addDamagedBook(id, num);
}

void ProxyLibraryDatabase::addBook(QString id, QString name, QString author, QString publisher, QString tags, int num){
    if(this->check()) this->_libdata->addBook(id, name, author, publisher, tags, num);
}   //add new kind of book

void ProxyLibraryDatabase::addBook(QString id, int num){
    if(this->check()) this->_libdata->addBook(id, num);
}

void ProxyLibraryDatabase::deleteBook(QString id){
    if(this->check()) this->_libdata->deleteBook(id);
}

void ProxyLibraryDatabase::deleteBook(QString id, int num){
    if(this->check()) this->_libdata->deleteBook(id, num);
}

QVector<Book> ProxyLibraryDatabase::viewBorrowedBook(){
    if(this->check()) return this->_libdata->viewBorrowedBook();
};

QVector<Book>ProxyLibraryDatabase::viewDamagedBook(){
    if(this->check()) return this->_libdata->viewDamagedBook();
};
