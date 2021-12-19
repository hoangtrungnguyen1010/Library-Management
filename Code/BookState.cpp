#include"BookState.h"

int BookState::getNumOfRemaingBooks(){
    return this->_quantity- this->_numOfBorrowedBooks;
}

BookState::BookState(){
    this->_quantity=1;
    this->_numOfBorrowedBooks=0;
    this->_numOfDamagedBooks=0;
}

BookState::BookState(int quantity, int numOfBorrowedBooks, int numOfDamagedBooks){
    this->_quantity=quantity;
    this->_numOfBorrowedBooks=numOfBorrowedBooks;
    this->_numOfDamagedBooks=numOfDamagedBooks;
}

void BookState:: updateQuantiy(int num){
    this->_quantity++;
}

void BookState::updateBorrowedBooks(int num){
    this->_numOfBorrowedBooks++;
}

void BookState::updateDamagedBooks(int num){
    this->_numOfDamagedBooks++;
}

