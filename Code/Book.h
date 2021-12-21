#pragma once
#include<QString>
#include<sstream>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include"BookState.h"
using namespace std;

class Book : public BookState{
private:
    QString _name;
    QString _ISBN;
    QString _publisher;
    QString _author;
    QString _tag;
    BookState state;
public:
    QString getID();
    QString getName();
public:
    Book();
    Book( QString ISBN, QString name, QString publisher, QString author, QString tag, int quality, int numOfBorrowedBooks, int numOfDamagedBooks );
    QString toString() const;
};
