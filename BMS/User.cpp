#include<User.h>

User::User(){
    QVector<Book*> cart;
    QVector<Book*> borrowedBook;
    QVector<bool> checkExtended; //remaining time corespoding to each book
    QVector<QDateTime> timeWhenBorrowed;
    this->_cart=cart;
    this->_borrowedBook = borrowedBook;
    this->_checkExtended=checkExtended;
    this->_timeWhenBorrowed=timeWhenBorrowed;
};

void User::addToCart(Book* b){
    this->_cart.push_back(b);
}

int User::getTimeRemainingBook(Book book){
    int i = this->getPosBookInBorrowedBookStack(book);
    int timeRemaining = User::_BorrowingTime-this->_timeWhenBorrowed[i].daysTo(QDateTime::currentDateTime());
    if (_checkExtended[i]==1){
        timeRemaining+=User::_ExtendedBorrowingTime;
    }
    return timeRemaining;
}

bool User::borrowBook(Book* book){
    if(book->getNumOfRemaingBooks()==0) return 0;

    for(int i = 0; i < this->_borrowedBook.size();i++){
        if (book->getID()==this->_borrowedBook[i]->getID()) return 0;
    }

    if(this->_borrowedBook.size()==User::numOfBooksCanBorrowAtTheSameTime) return 0;
//    book->updateBorrowedBooks(1);

    this->_borrowedBook.push_back(book);

    QDateTime cd= QDateTime::currentDateTime();

    for(auto i : this->_borrowedBook){
        qDebug()<<i->getName();
    }
    this->_timeWhenBorrowed.push_back(cd);
    return 1;
}


bool User::borrowBook(Book* book, bool checkExtended, QString time){
    if(book->getNumOfRemaingBooks()==0) return 0;
    book->updateBorrowedBooks(1);
    this->_checkExtended.push_back(checkExtended);
    this->_borrowedBook.push_back(book);

    QDateTime dateTime(QDateTime::fromString(time, "hh:mm:ss dd-MM-yyyy"));

    this->_timeWhenBorrowed.push_back(dateTime);
    return 1;
}

void User::returnBook(Book* book){
    book->updateBorrowedBooks(-1);
    int pos=getPosBookInBorrowedBookStack(*book);
    this->_borrowedBook.erase(this->_borrowedBook.begin()+pos);
    this->_timeWhenBorrowed.erase(this->_timeWhenBorrowed.begin()+pos);
}

QString User::BorrowedBookToString()
{
    QString res;
    if(_borrowedBook.size()!=0){
        for(auto book:_borrowedBook)
        {
            res+="- "+book->getName()+'\n';
        }
        return res;
    }
    else return "None";
}
QString User::ExpiredBookToString(){
   QString res="";
    for(auto book:_borrowedBook){
        if(this->getTimeRemainingBook(*book)<0){
            res+="- "+ book->getName()+'\n';
        }
    }
    if(res!=""){
        return res;
    }
    return "None";
}


QVector<Book*>User::viewBorrowedBook(){
    return this->_borrowedBook;
}

void User::extendBorrowedTime(Book book){
   int pos=getPosBookInBorrowedBookStack(book);
   _checkExtended[pos]=1;
}

int User::getPosBookInBorrowedBookStack(Book book){
    int size = this->_borrowedBook.size();
    for(int i=0; i<size;i++){
        if(book.getID()==this->_borrowedBook[i]->getID()){
            return i;
        }
    }
    return -1;
}



QString User::toString() {
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    out<<Person::toString();
    out<<"|User";
    out<<this->toStringUsingInfo();

    QString res=out.readAll();
    return res;
}

QString User::toStringPersonalInfo(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    out<<Person::toString();

    QString res=out.readAll();
    return res;
}

QString User::toStringUsingInfo(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    int cartSize=this->_cart.size();
    for(int i=0;i<cartSize;i++){
        out<<"|c,"<<_cart[i]->getID();
    }

    int borrowedBookSize=this->_borrowedBook.size();
    for(int i=0;i<borrowedBookSize;i++){
        out<<"|b,"<<_borrowedBook[i]->getID();
        out<<"|"<<_checkExtended[i];
        out<<"|"<<_timeWhenBorrowed[i].toString("hh:mm:ss dd-MM-yyyy");
    }

    QString res=out.readAll();
    return res;
}
