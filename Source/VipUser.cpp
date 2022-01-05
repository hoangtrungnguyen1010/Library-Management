#include<iostream>
#include"VipUser.h"

VipUser::VipUser():User(){
    this->_type="Vip User";
}

VipUser::VipUser(QString id, QString name, bool gender, QString address, QString username, QString password):User(id,name,gender,address,username,password)
{
    this->_type="Vip User";
}

int VipUser::getTimeRemainingBook(Book book){
   int i = this->getPosBookInBorrowedBookStack(book);
   int timeRemaining = VipUser::_BorrowingTime-this->_timeWhenBorrowed[i].daysTo(QDateTime::currentDateTime());
   if (_checkExtended[i]==1){
       timeRemaining+=VipUser::_ExtendedBorrowingTime;
   }
   return timeRemaining;

}
bool VipUser::borrowBook(Book book){
    if(book.getNumOfRemaingBooks()==0) return 0;

    for(int i = 0; i < this->_borrowedBook.size();i++){
        if (book.getID()==this->_borrowedBook[i].getID()) return 0;
    }

    if(this->_borrowedBook.size()==VipUser::numOfBooksCanBorrowAtTheSameTime) return 0;

    this->_borrowedBook.push_back(book);

    QDateTime cd= QDateTime::currentDateTime();

    this->_timeWhenBorrowed.push_back(cd);
    this->_checkExtended.push_back(0);
    ProxyLibraryDatabase* proxy=new ProxyLibraryDatabase;
    int remain_cur=proxy->getQuantity(book.getID());
    proxy->updateQuantity(book.getID(),remain_cur-1);
    proxy->updateBorrowed(book.getID(),proxy->getBorrowed(book.getID())+1);
    int posInCart=this->getPosBookInCartBookStack(book);
    if(posInCart>=0)
        _cart[posInCart].updateQuantiy(remain_cur-1);
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
