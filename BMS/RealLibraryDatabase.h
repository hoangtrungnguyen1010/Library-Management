#ifndef REALLIBRARYDATABASE_H
#define REALLIBRARYDATABASE_H
#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include <QVector>
#include <QDir>
//#include"QuickSort.h"
#include"LibraryDatabase.h"
extern const QDir CURRENT_PATH;
class RealLibraryDatabase : public LibraryDatabase{
private: static RealLibraryDatabase* Instance;
public:
    static RealLibraryDatabase* getInstance();
private:
    QString _fileName = CURRENT_PATH.relativeFilePath("debug/Resource/Data/BookData.txt");
    QVector<Book> List;
public:
    void sortByID();
    void sortByName();

    void uploadBook();

    QVector<Book> findBookByName(QString name);
    QVector<Book> findBookByID(QString id);

    int getBookPos(QString id);
    Book* getBookByID(QString ID);

    void addDamagedBook(QString id, int num);
    bool addBook(QString id, QString name, QString author, QString publisher, QString tags, int num);   //add new kind of book
    bool addBook(QString id, int num);

    void deleteBook(QString id); //delete all
    void deleteBook(QString id, int num);

    QString toString() const;

    QVector<Book> getListBook();
    QVector<Book> viewBorrowedAndDamagedBook();

    int getQuantity(QString ID);
    int getDamaged(QString ID);

    bool  updateQuantity(QString ID,int num);
    bool updateDamaged(QString ID,int num);

    void saveDTB();

};


#endif // REALLIBRARYDATABASE_H
