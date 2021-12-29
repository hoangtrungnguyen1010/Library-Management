#ifndef PROXYLIBRARYDATABASE_H
#define PROXYLIBRARYDATABASE_H
#include"RealLibraryDatabase.h"
class ProxyLibraryDatabase: public LibraryDatabase{
private:
    bool _type; //User=0  Admin =1
    RealLibraryDatabase * _libdata;
public:
    void sortByID();
    void sortByName();

    bool findBookByName(QString name, Book& res);
    bool findBookByID(QString id, Book& res);

    void addDamagedBook(QString id, int num);
    void addBook(QString id, QString name, QString author, QString publisher, QString tags, int num);   //add new kind of book
    void addBook(QString id, int num);

    void deleteBook(QString id); //delete all
    void deleteBook(QString id, int num);

    void viewBorrowedBook();
    void viewDamagedBook();


};

#endif // PROXYLIBRARYDATABASE_H
