 #include<iostream>
#include"VipUser.h"

unsigned long long VipUser::getTimeRemaining(Book book){
    int i = this->getPosBookInBorrowedBookStack(book);
    int timeRemaining = User::_BorrowingTime-this->_timeWhenBorrowed[i].secsTo(QDateTime::currentDateTime());
    if (_checkExtended[i]==1){
        timeRemaining+=3600*24*User::_ExtendedBorrowingTime*2;
    }
    return timeRemaining;

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
