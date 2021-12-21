#include"LibraryDatabase.h"
#include"QuickSort.h"

void LibraryDatabase::uploadBook() {
    QFile fin(_fileName);
    fin.open(QIODevice::ReadOnly);
    QTextStream in(&fin);
    while (!in.atEnd()) {

        QString line=in.readLine();

        QStringList list=line.split('|');
        if (list.size()!=7) continue;
       Book newBook(list.at(0),list.at(1),list.at(2),list.at(3),list.at(4), list.at(5).toInt(), 0,list.at(6).toInt());
       List.push_back(newBook);
    }
    fin.close();

}

QString LibraryDatabase::toString() const{
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    int size=List.length();
    for (int i=0;i<size;i++) {
      out<<List[i].toString()<<"\n";
	}
    return out.readAll();
}

bool LibraryDatabase::findBookByName(QString name, Book &res){
    int size=this->List.size();

    for(int i=0;i<size;i++){
        if (QString::compare(this->List[i].getName(),name)==0){
            res=this->List[i];
            return 1;
        }
    }
    return 0;
}

bool LibraryDatabase::findBookByID(QString ID, Book& res){
    int size=this->List.size();

    for(int i=0;i<size;i++){
        if (QString::compare(this->List[i].getID(),ID)==0){
            res=this->List[i];
            return 1;
        }
    }
    return 0;
}

void LibraryDatabase::sortByID(){
    int last=this->List.size()-1;
    quickSortID(this->List, 0, last );
}

void LibraryDatabase::sortByName(){
    int last=this->List.size()-1;
    quickSortName(this->List, 0, last );
}

int LibraryDatabase::getBookPos(QString id){
    int size=this->List.size();
    for(int i=0;i<size;i++){
        if (QString::compare(this->List[i].getName(),id)==0){
            return i;
        }
    }
    return -1;
}

void LibraryDatabase::addDamagedBook(QString id, int num){
    int pos = getBookPos(id);
    this->List[pos].updateDamagedBooks(num);
}

void LibraryDatabase::addBook(QString id, QString name, QString author, QString publisher, QString tags, int num){
    Book temp(id, name, author, publisher, tags, num,0,0);
    this->List.push_back(temp);
}   //add new kind of book

void LibraryDatabase::addBook(QString id, int num){
    int pos = getBookPos(id);
    this->List[pos].updateQuantiy(1);
}

void LibraryDatabase::deleteBook(QString id){
    int pos=getBookPos(id);
    this->List.erase(this->List.begin()+pos);
}

void LibraryDatabase::deleteBook(QString id, int num){
    int pos=getBookPos(id);
    this->List[pos].updateQuantiy(-num);
    if(this->List[pos].getNumOfRemaingBooks()<0){
        this->List.erase(this->List.begin()+pos);
    }
}

void LibraryDatabase::saveDTB(){
    int size = List.size();

    QFile file(_fileName);
    if ( file.open(QIODevice::ReadWrite) ){
        QTextStream stream( &file );
        for(int i=0;i<size;i++){
            stream<<List[i].toString()<<"\n";
        }
    }
}

void LibraryDatabase::viewBorrowedBook(){

};

void LibraryDatabase::viewDamagedBook(){};
