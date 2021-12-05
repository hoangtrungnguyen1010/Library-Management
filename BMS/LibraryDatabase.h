#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include <QVector>
#include"Book.h"

class LibraryDatabase {
private:
    QString fileName = "../BookData.txt" ;
    QVector<Book> List;
public:
	void uploadBook();
    QString viewListBook() ;
};

