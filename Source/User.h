#pragma once
#ifndef USER_H
#define USER_H
#include<iostream>
#include<QVector>
#include"Person.h"
#include"Book.h"
#include "ProxyLibraryDataBase.h"
#include<QDateTime>

class User:public Person{

protected:
    QVector<Book> _cart;
    QVector<Book> _borrowedBook;
    QVector<QDateTime> _timeWhenBorrowed;
    QVector<bool> _checkExtended; //extend time returning book for 5 days.
protected:
    const static int numOfBooksCanBorrowAtTheSameTime = 5;
    const static int _ExtendedBorrowingTime = 5;
    const static int _BorrowingTime = 15;
public:
    User();
    virtual ~User(){};
     User(QString id, QString name, bool gender, QString address, QString username, QString password);

public:

    void addToCart(Book b);
    virtual bool borrowBook(Book book);
    virtual bool borrowBook(Book book, bool checkExtended, QString time);        //use to upload database.


    virtual int getTimeRemainingBook(Book book); //return days
    virtual bool extendBorrowedTime(Book book);
    //return sec

    void returnBook(Book book);
    void deleteCartBook(Book book);
    QVector<Book> viewBorrowedBook();
    QString BorrowedBookToString();
    QString ExpiredBookToString();

    int getPosBookInBorrowedBookStack(Book book);
    int getPosBookInCartBookStack(Book book);

    virtual QString toString();

    QString toStringPersonalInfo(); // for Vip User overriding toString()
    QString toStringUsingInfo();    // for Vip User overriding toString()

    QVector<Book> getBorrowedBook(){ return _borrowedBook;}
    QVector<Book> getInCartBook(){return _cart;}
    QVector<QDateTime> getStartedTime(){return _timeWhenBorrowed;}
};

#endif // USER_H
