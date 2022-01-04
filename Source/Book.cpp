#include"Book.h"

QString Book:: getID(){
    return this->_ISBN;
}

QString Book:: getName(){
    return this->_name;
}
QString Book::getPublisher()
{
    return this->_publisher;
}
QString Book::getAuthor()
{
    return this->_author;
}
QString Book::getTag(){
    return this->_tag;
}
Book::Book(){
    _name = "unknown";
    _ISBN = "unknown";
    _publisher = "unknown";
    _author = "unknown";
    _tag = "unknown";
}

Book::~Book(){
    delete state;
}
Book::Book(QString ISBN,QString name,  QString publisher, QString author, QString tag, int quatity, int numOfBorrowedBooks, int numOfDamagedBooks ) {
    _name = name;
    _ISBN = ISBN;
    _publisher = publisher;
    _author = author;
    _tag = tag;
    BookState* temp= new BookState(quatity, numOfBorrowedBooks, numOfDamagedBooks);
    state = temp;
}

int Book::getNumOfRemaingBooks(){
    return this->state->getNumOfRemaingBooks();
}

int Book::getNumOfDamagedBooks(){
    return this->state->getNumOfDamagedBooks();
}

int Book::getNumOfOfBorrowedBooks(){
    qDebug()<<this->state->getNumOfOfBorrowedBooks();
    return this->state->getNumOfOfBorrowedBooks();
}

void Book::updateQuantiy(int num){
    this->state->updateQuantiy(num);
}
void Book::updateBorrowedBooks(int num){
    this->state->updateBorrowedBooks(num);

}
void Book::updateDamagedBooks(int num){
    this->state->updateDamagedBooks(num);
}

QString Book::toString() const{
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    out<<this->_ISBN ;
    out<<"|"<<this->_name;
    out<< "|" << this->_author;
    out << "|" << this->_publisher;
    out << "|" << this->_tag ;
    out<<this->state->toString();

    QString res=out.readAll();
    return res;
}
