#include"ProxyLibraryDatabase.h"


QVector<Book*> ProxyLibraryDatabase::findBookByName(QString name){
    return this->_wrappee->findBookByName(name);
}

QVector<Book*> ProxyLibraryDatabase::findBookByID(QString id){
    return this->_wrappee->findBookByID(id);
}

void ProxyLibraryDatabase::sortByID(){
    this->_wrappee->sortByID();
}

void ProxyLibraryDatabase::sortByName(){
    this->_wrappee->sortByName();
}

void ProxyLibraryDatabase::addDamagedBook(QString id, int num){
    if(this->check()) this->_wrappee->addDamagedBook(id, num);
}

void ProxyLibraryDatabase::addBook(QString id, QString name, QString author, QString publisher, QString tags, int num){
    if(this->check()) this->_wrappee->addBook(id, name, author, publisher, tags, num);
}   //add new kind of book

void ProxyLibraryDatabase::addBook(QString id, int num){
    if(this->check()) this->_wrappee->addBook(id, num);
}

void ProxyLibraryDatabase::deleteBook(QString id){
    if(this->check()) this->_wrappee->deleteBook(id);
}

void ProxyLibraryDatabase::deleteBook(QString id, int num){
    if(this->check()) this->_wrappee->deleteBook(id, num);
}

QVector<Book> ProxyLibraryDatabase::getListBook()
{
    return this->_wrappee->getListBook();
}
QVector<Book> ProxyLibraryDatabase::viewBorrowedBook(){
    QVector<Book> res;
    if(this->check()) return this->_wrappee->viewBorrowedBook();
    else return res;
};

QVector<Book>ProxyLibraryDatabase::viewDamagedBook(){
    QVector<Book> res;
    if(this->check()) return this->_wrappee->viewDamagedBook();
    else return res;
};
