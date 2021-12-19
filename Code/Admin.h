#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include"Person.h"
#include"Book.h"

class Admin: public Person{
private:

public:
    Admin(){};
    Admin(QString id, QString name, QString gender, QString address, QString account, QString password);
    void viewBorrowedBook();
    void viewDamagedBook();
    void addBook(Book addedBook, int num);
    void deleteBook(Book delBook, int num);
};

#endif // ADMIN_H
