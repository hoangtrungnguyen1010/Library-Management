#include"LibraryDatabase.h"
#include"QuickSort.h"
void LibraryDatabase::uploadBook() {
    QFile fin(fileName);
    fin.open(QIODevice::ReadOnly);
    QTextStream in(&fin);
    while (!in.atEnd()) {
        QString line=in.readLine();

        QStringList list=line.split(',');

       Book newBook(list.at(0),list.at(1),list.at(2),list.at(3),list.at(4));
       List.push_back(newBook);
    }
}

QString LibraryDatabase::viewListBook(){
    QString buffer="";
    QTextStream out(&buffer,QIODevice::ReadWrite);
    for (int i=0;i<List.length();i++) {
      out<<i+1<<"."<<List.at(i).showBookInfor()<<"\n";
	}
    return out.readAll();
}

bool LibraryDatabase::findBook(QString name, Book& res){
    int size=this->List.size();

    for(int i=0;i<size;i++){
        if (QString::compare(this->List[i].getName(),name)==0){
            res=this->List[i];
            return 1;
        }
    }
    return 0;
}


void LibraryDatabase::sortByID(){
    int last=this->List.size()-1;
    quickSortID(this->List, 0, last );
    for(int i=0;i<=last;i++){
        qDebug()<<List[i].getID()<<"\n";
    }
}

void LibraryDatabase::sortByName(){
    int last=this->List.size()-1;
    quickSortName(this->List, 0, last );
    for(int i=0;i<=last;i++){
        qDebug()<<List[i].getName()<<"\n";
    }
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

void LibraryDatabase::addBook(QString id, int num){
    int pos=getBookPos(id);
    this->List[pos].updateQuantiy(1);
}

//    void sortByName();
//    void uploadBook();
//    bool findBook(QString name, Book& res);
//    QString viewListBook() ;
