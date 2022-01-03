#ifndef PROXYLIBRARYDATABASE_H
#define PROXYLIBRARYDATABASE_H
#include"RealLibraryDatabase.h"
class ProxyLibraryDatabase: public LibraryDatabase{
private:
    bool _type; //User=0  Admin =1
    RealLibraryDatabase * _wrappee= RealLibraryDatabase::getInstance();
public:
    ProxyLibraryDatabase(){
        _wrappee=RealLibraryDatabase::getInstance();
    }
    ProxyLibraryDatabase(bool type){
        _type=type;
         _wrappee=RealLibraryDatabase::getInstance();
    }
    ~ProxyLibraryDatabase(){
        delete _wrappee;
    }
public:
    bool check(){
        if(_type) return 1;
        return 0;
    }
    void sortByID();
    void sortByName();

    QVector<Book> findBookByName(QString name);
    QVector<Book> findBookByID(QString id);

    void addDamagedBook(QString id, int num);
    bool addBook(QString id, QString name, QString author, QString publisher, QString tags, int num);   //add new kind of book
    bool addBook(QString id, int num);

    void deleteBook(QString id); //delete all
    void deleteBook(QString id, int num);

    QVector<Book> getListBook();
    QVector<Book> viewBorrowedAndDamagedBook();

    bool  updateQuantity(QString ID,int num);
    bool updateDamaged(QString ID,int num);

};

#endif // PROXYLIBRARYDATABASE_H
