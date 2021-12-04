#pragma once
#include"LibraryDatabase.h"

void LibraryDatabase::uploadBook() {
	ifstream fin(fileName);
	string temp;
	string name, ISBN, publisher, author, tag;
	while (!fin.eof()) {
		getline(fin, temp);
		stringstream ss(temp);
		getline(ss, ISBN, ',');
		getline(ss, name, ',');
		getline(ss, publisher, ',');
		getline(ss, author, ',');
		getline(ss, tag, ',');
		Book newBook(name, ISBN, publisher, author, tag);
		this->List.push_back(newBook);
	}
}

void LibraryDatabase::viewListBook() {
	for (auto i : List) {
		i.showBookInfor();
		cout << endl;
	}
}
