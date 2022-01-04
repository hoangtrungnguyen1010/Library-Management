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

    virtual QVector<Book> findBookByName(QString name)=0;
    virtual QVector<Book> findBookByID(QString id)=0;

    virtual void addDamagedBook(QString id, int num)=0;
    virtual bool addBook(QString id, QString name, QString author, QString publisher, QString tags, int num)=0;   //add new kind of book
    virtual bool addBook(QString id, int num)=0;

    virtual bool deleteBook(QString id)=0; //delete all
    virtual void deleteBook(QString id, int num)=0;

    virtual QVector<Book> getListBook()=0;

    virtual int getQuantity(QString ID)=0;
    virtual int getDamaged(QString ID)=0;
    virtual int getBorrowed(QString ID)=0;

    virtual bool updateBorrowed(QString ID,int num)=0;
    virtual bool updateQuantity(QString ID,int num)=0;
     virtual bool updateDamaged(QString ID,int num)=0;


};

