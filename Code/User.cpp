#include<User.h>

bool User::borrowBook(Book book){
    if(book.getNumOfRemaingBooks()==0) return 0;
    book.updateBorrowedBooks(1);
    this->_borrowedBook.push_back(book);
    QDateTime cd= QDateTime::currentDateTime();
    this->_timeWhenBorrowed.push_back(cd);
    return 1;
}

void User::returnBook(Book book){
    book.updateBorrowedBooks(-1);

}

void User::addToCart(Book b){
    this->_cart.push_back(b);
}

QVector<Book>User::viewBorrowedBook(){
    return this->_borrowedBook;
}

bool User::extendBorrowedTime(){
    return 1;
}

int getNumOfRemaingBooks();

int User::getPosBookInBorrowedBookStack(Book book){
    int size = this->_borrowedBook.size();
    for(int i=0; i<size;i++){
        if(book.getID()==this->_borrowedBook[i].getID()){
            return i;
        }
    }
    return -1;
}
