#include"RealLibraryDatabase.h"
#include"QuickSort.h"
#include"SearchHelper.h"

void RealLibraryDatabase::uploadBook() {
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

RealLibraryDatabase* RealLibraryDatabase::getInstance()
{
     if(Instance==nullptr){
         Instance=new RealLibraryDatabase;
         Instance->uploadBook();
     }
     return Instance;
}

QString RealLibraryDatabase::toString() const{
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);

    int size=List.length();
    for (int i=0;i<size;i++) {
      out<<List[i].toString()<<"\n";
    }
    return out.readAll();
}

QVector<Book> RealLibraryDatabase::findBookByName(QString name){

    int size=this->List.size();
    QVector<int> similarity;
    QVector<Book> res;
    for(int i=0;i<size;i++){
        double temp = similarityBetweenTwoString(name, this->List[i].getName());
        if (temp > 0) {
            res.push_back(this->List[i]);
            similarity.push_back(temp);
        }
    }
    quickSortSimilarity(res,similarity, 0, res.size()-1);
    return res;
}

QVector<Book> RealLibraryDatabase::findBookByID(QString ID){
    int size=this->List.size();
    QVector<Book> res;
    for(int i=0;i<size;i++){
        if (QString::compare(this->List[i].getID(),ID)==0){
            res.push_back(this->List[i]);
        }
    }
    return res;
}

void RealLibraryDatabase::sortByID(){
    int last=this->List.size()-1;
    quickSortID(this->List, 0, last );
}

void RealLibraryDatabase::sortByName(){
    int last=this->List.size()-1;
    quickSortName(this->List, 0, last );
}

int RealLibraryDatabase::getBookPos(QString id){
    int size=this->List.size();
    for(int i=0;i<size;i++){
        if (QString::compare(this->List[i].getName(),id)==0){
            return i;
        }
    }
    return -1;
}

void RealLibraryDatabase::addDamagedBook(QString id, int num){
    int pos = getBookPos(id);
    this->List[pos].updateDamagedBooks(num);
}

void RealLibraryDatabase::addBook(QString id, QString name, QString author, QString publisher, QString tags, int num){
    Book temp(id, name, author, publisher, tags, num,0,0);
    this->List.push_back(temp);
}   //add new kind of book

void RealLibraryDatabase::addBook(QString id, int num){
    int pos = getBookPos(id);
    this->List[pos].updateQuantiy(1);
}

void RealLibraryDatabase::deleteBook(QString id){
    int pos=getBookPos(id);
    this->List.erase(this->List.begin()+pos);
}

void RealLibraryDatabase::deleteBook(QString id, int num){
    int pos=getBookPos(id);
    this->List[pos].updateQuantiy(-num);
    if(this->List[pos].getNumOfRemaingBooks()<0){
        this->List.erase(this->List.begin()+pos);
    }
}

void RealLibraryDatabase::saveDTB(){
    int size = List.size();

    QFile file(_fileName);
    if ( file.open(QIODevice::ReadWrite) ){
        QTextStream stream( &file );
        for(int i=0;i<size;i++){
            stream<<List[i].toString()<<"\n";
        }
    }
}
QVector<Book> RealLibraryDatabase::getListBook(){
    return this->List;
}

QVector<Book> RealLibraryDatabase::viewBorrowedBook(){
    QVector<Book> res;
    for(auto i: this->List){
        if (i.getNumOfOfBorrowedBooks() > 0 ){
            res.push_back(i);
        }
    }
    return res;
};

QVector<Book> RealLibraryDatabase::viewDamagedBook(){
    QVector<Book> res;
    for(auto i: this->List){
        if (i.getNumOfDamagedBooks() > 0 ){
            res.push_back(i);
        }
    }
    return res;
};
