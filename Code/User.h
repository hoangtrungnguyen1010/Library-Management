#pragma once
#ifndef USER_H
#define USER_H
#include<iostream>
#include<QVector>
#include"Person.h"
#include"Book.h"

class User:public Person{
private:
    const int _BorrowingTime = 15;
    const int _ExtendedBorrowingTime=5;
    QVector<Book> _cart;
    QVector<Book> _borrowedBook;
    QVector<int> _remainingTime; //remaining time corespoding to each book
    QVector<QDateTime> _timeWhenBorrowed;
public:
    User(){};
    User(QString id, QString name, QString gender, QString address, QString username, QString password):Person(id,name, gender,address,username, password){};
    bool borrowBook(Book book);
    void returnBook(Book book);
    void addToCart(Book b);
    QVector<Book> viewBorrowedBook();
    bool extendBorrowedTime();
    int getPosBookInBorrowedBookStack(Book book);
};

#endif // USER_H
