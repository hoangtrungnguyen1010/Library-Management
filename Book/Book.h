#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Book {
private:
	string _name;
	string _ISBN;
	string _publisher;
	string _author;
	string _tag;
public:
	Book(string name, string ISBN, string publisher, string author, string tag );
	void showBookInfor();
};