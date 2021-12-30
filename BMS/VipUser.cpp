 #include<iostream>
#include"VipUser.h"

int VipUser::getTimeRemaining(Book book){
    int i = this->getPosBookInBorrowedBookStack(book);
    int timeRemaining = VipUser::_BorrowingTime-this->_timeWhenBorrowed[i].secsTo(QDateTime::currentDateTime());
    if (_checkExtended[i]==1){
        timeRemaining+=3600*24*VipUser::_ExtendedBorrowingTime;
    }
    return timeRemaining%(3600*24);

}
bool VipUser::borrowBook(Book book){
    if(book.getNumOfRemaingBooks()==0) return 0;
    if(this->_borrowedBook.size()== VipUser::numOfBooksCanBorrowAtTheSameTime) return 0;
    book.updateBorrowedBooks(1);
    this->_borrowedBook.push_back(book);
    QDateTime cd= QDateTime::currentDateTime();
    this->_timeWhenBorrowed.push_back(cd);
    return 1;
}


QString VipUser::toString(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    out<<Person::toString();
    out<<"|Vip User";
    out<<this->toStringUsingInfo();

    QString res=out.readAll();
    return res;

}
