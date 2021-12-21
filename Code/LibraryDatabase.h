#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include <QVector>
//#include"QuickSort.h"
#include"Book.h"

class LibraryDatabase : public Book{

public:

    virtual void sortByID() =0;
    virtual void sortByName()=0;

    virtual bool findBookByName(QString name, Book& res)=0;
    virtual bool findBookByID(QString id, Book& res)=0;

    virtual void addDamagedBook(QString id, int num)=0;
    virtual void addBook(QString id, QString name, QString author, QString publisher, QString tags, int num)=0;   //add new kind of book
    virtual void addBook(QString id, int num)=0;

    virtual void deleteBook(QString id)=0; //delete all
    virtual void deleteBook(QString id, int num)=0;

    virtual void viewBorrowedBook()=0;
    virtual void viewDamagedBook()=0;

};

