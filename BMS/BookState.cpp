#include"BookState.h"
#include<QDebug>

int BookState::getNumOfRemaingBooks(){
    return this->_quantity - this->_numOfBorrowedBooks - this->_numOfDamagedBooks;
}

int BookState::getNumOfDamagedBooks(){
    return this->_numOfDamagedBooks;
}

int BookState::getNumOfOfBorrowedBooks(){
    return this->_numOfBorrowedBooks;
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

void BookState::updateQuantiy(int num){
    this->_quantity+= num ;
}

void BookState::updateBorrowedBooks(int num){
    this->_numOfBorrowedBooks+= num;
}

void BookState::updateDamagedBooks(int num){
    this->_numOfDamagedBooks+= num;
}

QString BookState::toString() const{
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);
    out<<"|"<<QString::number(this->_quantity);
    out<<"|"<<QString::number(this->_numOfDamagedBooks);

    QString res=out.readAll();
    return res;
}
