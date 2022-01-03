#include"RealLibraryDatabase.h"
#include"QuickSort.h"
#include "SearchHelper.h"

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
            qDebug()<<List[i].getName();
        }
    }
    qDebug()<<res.size();

    if (!res.empty()) quickSortSimilarity(res,similarity, 0, res.size()-1);
    qDebug()<<"TRue";

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

Book* RealLibraryDatabase::getBookByID(QString ID){
    int size=this->List.size();
    for(int i=0;i<size;i++){
        if (QString::compare(this->List[i].getID(),ID)==0){
            return &this->List[i];
        }
    }
    return NULL;
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
        if (QString::compare(this->List[i].getID(),id)==0){
            return i;
        }
    }
    return -1;
}

void RealLibraryDatabase::addDamagedBook(QString id, int num){
    int pos = getBookPos(id);
    this->List[pos].updateDamagedBooks(num);
}

bool RealLibraryDatabase::addBook(QString id, QString name, QString author, QString publisher, QString tags, int num){
    Book temp(id, name, author, publisher, tags, num,0,0);
    this->List.push_back(temp);
    return true;
}   //add new kind of book

bool RealLibraryDatabase::addBook(QString id, int num){
    int pos = getBookPos(id);
    this->List[pos].updateQuantiy(List[pos].getNumOfRemaingBooks()+num);
    return true;
}

void RealLibraryDatabase::deleteBook(QString id){
    int pos=getBookPos(id);
    this->List.erase(this->List.begin()+pos);
}

void RealLibraryDatabase::deleteBook(QString id, int num){
    int pos=getBookPos(id);
    this->List[pos].updateQuantiy(List[pos].getNumOfRemaingBooks()-num);
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
   qDebug()<<List[0].getID();
   qDebug()<<List[0].getNumOfRemaingBooks();
    return this->List;

}
QVector<Book> RealLibraryDatabase::viewBorrowedAndDamagedBook(){
  QVector<Book> res;
  for(auto book:List){
      if(book.getNumOfDamagedBooks()!=0||book.getNumOfOfBorrowedBooks()!=0)
          res.push_back(book);
  }
  return res;
};

int  RealLibraryDatabase::getQuantity(QString ID){
    for(auto book:List){
        if(book.getID()==ID)
            return book.getNumOfRemaingBooks();
    }
    return -1;
}
int getDamaged(QString ID);

int RealLibraryDatabase::getDamaged(QString ID){
    for(auto book:List){
        if(book.getID()==ID)
            return book.getNumOfDamagedBooks();
    }
    return -1;
}
 bool RealLibraryDatabase::updateQuantity(QString ID,int num)
 {
     int size=List.size();
     for(int i=0;i<size;i++){
         if(QString::compare(List[i].getID(),ID)==0){
             List[i].updateQuantiy(num);
             qDebug()<<List[i].getNumOfRemaingBooks();
             return true;
         }
     }
     return false;
 }

 bool RealLibraryDatabase::updateDamaged(QString ID, int num)
 {
     for(auto book:List){
         if(QString::compare(book.getID(),ID)==0){
             book.updateDamagedBooks(num);
             qDebug()<<book.getNumOfRemaingBooks();
             return true;
         }
     }
     return false;
 }
