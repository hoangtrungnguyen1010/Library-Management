#include"Book.h"

QString Book:: getID(){
    return this->_ISBN;
}

QString Book:: getName(){
    return this->_name;
}

Book::Book(){
    _name = "unknown";
    _ISBN = "unknown";
    _publisher = "unknown";
    _author = "unknown";
    _tag = "unknown";
}

Book::Book(QString ISBN,QString name,  QString publisher, QString author, QString tag, int quality, int numOfBorrowedBooks, int numOfDamagedBooks ) {
	_name = name;
	_ISBN = ISBN;
	_publisher = publisher;
	_author = author;
	_tag = tag;
    BookState temp(quality, numOfBorrowedBooks, numOfDamagedBooks);
    state = temp;
}

QString Book::toString() const{
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    out<<this->_ISBN ;
    out<<"|"<<this->_name;
    out<< "|" << this->_author;
    out << "|" << this->_publisher;
    out << "|" << this->_tag ;
    out<<this->state.toString();

    QString res=out.readAll();
    return res;
}
