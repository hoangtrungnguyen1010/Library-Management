#pragma once
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include"Book.h"

class LibraryDatabase {
private:
	string fileName = "BookData.txt" ;
	vector<Book> List;
public:
	void uploadBook();
	void viewListBook();
};

