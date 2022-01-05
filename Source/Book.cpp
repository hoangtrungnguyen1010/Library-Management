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
    state=new BookState;
}

Book::~Book(){
    qDebug()<<this->_ISBN;
    if(state){
        delete state;
        state=nullptr;
    }
}
Book::Book(const Book& src){
    this->_ISBN=src._ISBN;
    _name=src._name;
    _publisher=src._publisher;
    _author=src._author;
    _tag = src._tag;
    state=new BookState(src.state->getNumOfRemaingBooks(),src.state->getNumOfOfBorrowedBooks(),src.state->getNumOfDamagedBooks());
}

Book& Book::operator=(const Book& src)
{
    if(state)
        delete state;
    this->_ISBN=src._ISBN;
    _name=src._name;
    _publisher=src._publisher;
    _author=src._author;
    _tag = src._tag;
    state=new BookState(src.state->getNumOfRemaingBooks(),src.state->getNumOfOfBorrowedBooks(),src.state->getNumOfDamagedBooks());
    return *this;
}
Book::Book(QString ISBN,QString name,  QString publisher, QString author, QString tag, int quatity, int numOfBorrowedBooks, int numOfDamagedBooks ) {
    _name = name;
    _ISBN = ISBN;
    _publisher = publisher;
    _author = author;
    _tag = tag;
    state = new BookState(quatity, numOfBorrowedBooks, numOfDamagedBooks);
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
