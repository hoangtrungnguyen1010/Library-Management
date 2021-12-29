#ifndef REALLIBRARYDATABASE_H
#define REALLIBRARYDATABASE_H
#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include <QVector>
//#include"QuickSort.h"
#include"LibraryDatabase.h"

class RealLibraryDatabase : public LibraryDatabase{
private: static RealLibraryDatabase* Instance;
public:
    static RealLibraryDatabase* getInstance();
private:
    QString _fileName = ":/Data/Resource/Data/BookData.txt" ;
    QVector<Book> List;
public:
    void sortByID();
    void sortByName();

    void uploadBook();

    QVector<Book> findBookByName(QString name);
    QVector<Book> findBookByID(QString id);

    int getBookPos(QString id);

    void addDamagedBook(QString id, int num);
    void addBook(QString id, QString name, QString author, QString publisher, QString tags, int num);   //add new kind of book
    void addBook(QString id, int num);

    void deleteBook(QString id); //delete all
    void deleteBook(QString id, int num);

    QString toString() const;

    QVector<Book> getListBook();
    void viewBorrowedBook();
    void viewDamagedBook();

    void saveDTB();

};


#endif // REALLIBRARYDATABASE_H
