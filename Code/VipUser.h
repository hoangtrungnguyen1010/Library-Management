#ifndef VIPUSER_H
#define VIPUSER_H
#include"User.h"
#include<LibraryDatabase.h>
class VipUser: public User{
public:
    const static int numOfBooksCanBorrowAtTheSameTime = 10;
    const static int _ExtendedBorrowingTime = 10;
    const static int _BorrowingTime = 30;
public:
    VipUser(QString id, QString name, bool gender, QString address, QString username, QString password)
      : User(id, name, gender, address, username, password){};
    int getTimeRemaining(Book book);
    bool borrowBook(Book*& book);
    QString toString();

};
#endif // VIPUSER_H
