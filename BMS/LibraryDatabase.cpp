#pragma once
#include"LibraryDatabase.h"

void LibraryDatabase::uploadBook() {
    QFile fin("C:/Users/DELL/Desktop/BMS/BookData.txt");
    fin.open(QIODevice::ReadOnly);
    QString temp;
    QString name, ISBN, publisher, author, tag;
    QTextStream in(&fin);
    while (!in.atEnd()) {
        QString line=in.readLine();
        QStringList list=line.split(',');
        qDebug()<<list.at(0);
       Book newBook(list.at(0),list.at(1),list.at(2),list.at(3),list.at(4));
       List.push_back(newBook);
}
}
QString LibraryDatabase::viewListBook(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);
    for (int i=0;i<List.length();i++) {
      out<<i+1<<"."<<List.at(i).showBookInfor()<<"\n";
    }
    return out.readAll();
}
