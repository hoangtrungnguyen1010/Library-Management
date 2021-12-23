#pragma once
#ifndef USER_H
#define USER_H
#include<iostream>
#include<QVector>
#include"Person.h"
#include"Book.h"
#include<QDateTime>

class User:public Person{

private:
    QVector<Book> _cart;
    QVector<Book> _borrowedBook;
protected:
    QVector<QDateTime> _timeWhenBorrowed;
    const static int _ExtendedBorrowingTime = 5;
    const static int _BorrowingTime = 15;

    QVector<bool> _checkExtended; //extend time returning book for 5 days.

public:
//    User operator=(const User& other){
//        this->_cart=other._cart;
//        this->_borrowedBook=other._borrowedBook;
//        this->_remainingTime=other._remainingTime;
//        this->_timeWhenBorrowed=other._timeWhenBorrowed;
//        return *this;
//    }
/*    virtual void getTimeRemaining();*/ //for all books borrowed
    User();
    User(QString id, QString name, bool gender, QString address, QString username, QString password):Person(id,name, gender,address,username, password)
    {};
    void addToCart(Book b);

    bool borrowBook(Book book);
    bool borrowBook(Book book, bool checkExtended, QString time);        //use to upload database.


    virtual unsigned long long getTimeRemainingBook(Book book); //return secs

    virtual void extendBorrowedTime(Book book);
    //return sec

    void returnBook(Book book);
    QVector<Book> viewBorrowedBook();
    int getPosBookInBorrowedBookStack(Book book);

    virtual QString toString();

    QString toStringPersonalInfo(); // for Vip User overriding toString()
    QString toStringUsingInfo();    // for Vip User overriding toString()
};

#endif // USER_H
