#pragma once
#include<QString>
#include<sstream>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include"BookState.h"
using namespace std;

class Book{
private:
    QString _name;
    QString _ISBN;
    QString _publisher;
    QString _author;
    QString _tag;
    BookState* state;
public:
    QString getID();
    QString getName();
    QString getPublisher();
    QString getAuthor();
    QString getTag();
public:
    Book();
    Book( QString ISBN, QString name, QString publisher, QString author, QString tag, int quatity, int numOfBorrowedBooks, int numOfDamagedBooks );
    ~Book();

public:
    int getNumOfRemaingBooks();
    int getNumOfDamagedBooks();
    int getNumOfOfBorrowedBooks();

    void updateQuantiy(int num);
    void updateBorrowedBooks(int num);
    void updateDamagedBooks(int num);


    QString toString() const;
};
