#pragma once
#include<QString>
#include<sstream>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDebug>
using namespace std;

class Book {
private:
    QString _name;
    QString _ISBN;
    QString _publisher;
    QString _author;
    QString _tag;
public:
    Book( QString ISBN,QString name, QString publisher, QString author, QString tag );
    QString showBookInfor() const;
};
