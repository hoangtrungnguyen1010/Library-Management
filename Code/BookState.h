#pragma once

#ifndef BOOKSTATE_H
#define BOOKSTATE_H
#include<iostream>
#include<QString>
#include<QTextStream>
using namespace std;

class BookState{
private:
    int _quantity=0;
    int _numOfBorrowedBooks=0;
    int _numOfDamagedBooks=0;
public:
    //initialize an object with quantity = 1, numOfBorrowedBooks = 0, numOfDamagedBooks =0;
    BookState();
    BookState(int quantity, int numOfBorrowedBooks, int numOfDamagedBooks);
    int getNumOfRemaingBooks();
    void updateQuantiy(int num);
    void updateBorrowedBooks(int num);
    void updateDamagedBooks(int num);
    QString toString() const;
};

#endif // BOOKSTATE_H
