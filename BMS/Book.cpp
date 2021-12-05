#include"Book.h"




Book::Book(QString ISBN,QString name,  QString publisher, QString author, QString tag) {
	_name = name;
	_ISBN = ISBN;
	_publisher = publisher;
	_author = author;
	_tag = tag;
}



QString Book::showBookInfor() const {
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);
    out<<this->_ISBN <<" || " << this->_name<<"\n";
    out<< "---Detailed info---" << '\n';
    out<< "Author: " << this->_author <<'\n';
    out << "Publisher: " << this->_publisher <<'\n';
    out << "Category: " << this->_tag << '\n';
    QString res=out.readAll();
    return res;
}
