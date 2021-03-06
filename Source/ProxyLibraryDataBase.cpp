#include"ProxyLibraryDatabase.h"


QVector<Book> ProxyLibraryDatabase::findBookByName(QString name){
    return this->_wrappee->findBookByName(name);
}

QVector<Book> ProxyLibraryDatabase::findBookByID(QString id){
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

bool ProxyLibraryDatabase::addBook(QString id, QString name, QString author, QString publisher, QString tags, int num){
    if(this->check()) return this->_wrappee->addBook(id, name, author, publisher, tags, num);
    else return false;
}   //add new kind of book

bool ProxyLibraryDatabase::addBook(QString id, int num){
    if(this->check()) return this->_wrappee->addBook(id, num);
    else return false;
}

bool ProxyLibraryDatabase::deleteBook(QString id){
    if(this->check()) return this->_wrappee->deleteBook(id);
    return false;
}

void ProxyLibraryDatabase::deleteBook(QString id, int num){
    if(this->check()) this->_wrappee->deleteBook(id, num);
}

QVector<Book> ProxyLibraryDatabase::getListBook()
{
    return this->_wrappee->getListBook();
}

int ProxyLibraryDatabase::getQuantity(QString ID)
{
    return _wrappee->getQuantity(ID);
}
int ProxyLibraryDatabase::getBorrowed(QString ID){
    return _wrappee->getBorrowed(ID);
}
int ProxyLibraryDatabase::getDamaged(QString ID)
{
    return _wrappee->getDamaged(ID);
}
bool ProxyLibraryDatabase::updateBorrowed(QString ID,int num)
{
    if(this->check()) return this->_wrappee->updateBorrowed(ID,num);
    return false;
}
bool ProxyLibraryDatabase::updateQuantity(QString ID,int num)
  {
      if(this->check()) return this->_wrappee->updateQuantity(ID,num);
      return false;
  }

bool ProxyLibraryDatabase::updateDamaged(QString ID, int num)
  {
      if(this->check()) return this->_wrappee->updateDamaged(ID,num);
      return false;
  }

