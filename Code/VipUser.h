#ifndef VIPUSER_H
#define VIPUSER_H
#include"User.h"
#include<LibraryDatabase.h>
class VipUser: public User{


public:
    VipUser(QString id, QString name, bool gender, QString address, QString username, QString password)
      : User(id, name, gender, address, username, password){};
    unsigned long long getTimeRemaining(Book book);
    QString toString();


};
#endif // VIPUSER_H
