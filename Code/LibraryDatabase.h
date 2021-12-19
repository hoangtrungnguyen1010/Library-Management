#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include <QVector>
//#include"QuickSort.h"
#include"Book.h"

class LibraryDatabase : public Book{
private:
    QString fileName = "..//Project/BookData.txt" ;
    QVector<Book> List;
public:
    void sortByID();
    void sortByName();
    void uploadBook();
    bool findBook(QString name, Book& res);
    int getBookPos(QString id);
    QString viewListBook();
    void addBook(QString id, int num);
};

