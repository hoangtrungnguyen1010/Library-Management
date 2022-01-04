#pragma once

#ifndef BOOKSTATE_H
#define BOOKSTATE_H
#include<iostream>
#include<QString>
#include<QTextStream>
#include <QFile>
#include <QIODevice>
using namespace std;

class BookState{
private:
    int _availQuantity=0;
    int _numOfBorrowedBooks=0;
    int _numOfDamagedBooks=0;
public:
    //initialize an object with quantity = 1, numOfBorrowedBooks = 0, numOfDamagedBooks =0;
    BookState();
    BookState(int quantity, int numOfBorrowedBooks, int numOfDamagedBooks);

    int getNumOfRemaingBooks();
    int getNumOfDamagedBooks();
    int getNumOfOfBorrowedBooks();

    void updateQuantiy(int num);
    void updateBorrowedBooks(int num);
    void updateDamagedBooks(int num);
    QString toString() const;
};

#endif // BOOKSTATE_H
