#include"Book.h"




Book::Book(string name, string ISBN, string publisher, string author, string tag) {
	_name = name;
	_ISBN = ISBN;
	_publisher = publisher;
	_author = author;
	_tag = tag;
}



void Book::showBookInfor() {
	cout << this->_ISBN << " || " << this->_name << endl;
	cout << "---Detailed info---" << endl;
	cout << "Author: " << this->_author << endl;
	cout << "Publisher: " << this->_publisher << endl;
	cout << "Category: " << this->_tag << endl;
}
