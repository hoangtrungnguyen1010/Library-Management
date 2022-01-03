#include"BookState.h"
#include<QDebug>

int BookState::getNumOfRemaingBooks(){
    return this->_availQuantity;
}

int BookState::getNumOfDamagedBooks(){
    return this->_numOfDamagedBooks;
}

int BookState::getNumOfOfBorrowedBooks(){
    return this->_numOfBorrowedBooks;
}

BookState::BookState(){
    this->_availQuantity=1;
    this->_numOfBorrowedBooks=0;
    this->_numOfDamagedBooks=0;
}

BookState::BookState(int quantity, int numOfBorrowedBooks, int numOfDamagedBooks){
    this->_availQuantity=quantity;
    this->_numOfBorrowedBooks=numOfBorrowedBooks;
    this->_numOfDamagedBooks=numOfDamagedBooks;
}

void BookState::updateQuantiy(int num){
    if(num>=0)
    this->_availQuantity= num ;
}

void BookState::updateBorrowedBooks(int num){
    if(num>=0)
    this->_numOfBorrowedBooks= num;
}

void BookState::updateDamagedBooks(int num){
    this->_numOfDamagedBooks+= num;
}

QString BookState::toString() const{
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);
    out<<"|"<<QString::number(this->_availQuantity);
    out<<"|"<<QString::number(this->_numOfDamagedBooks);

    QString res=out.readAll();
    return res;
}
