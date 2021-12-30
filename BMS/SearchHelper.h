#ifndef SEARCHHELPER_H
#define SEARCHHELPER_H
#include<QString>
#include<QDebug>
#include<QStringList>

double similarityBetweenTwoString(QString searchString, QString BookName){

    QStringList searchStringList = searchString.toLower().split(" ");
    QStringList BookNameList = BookName.toLower().split(" ");

    int similarity = 0;
    for(auto i : BookNameList){
        for(auto j : searchStringList){
            if (QString::compare(i,j)==0){
                similarity++;
            }
        }
    }
    return similarity*1.0/searchStringList.size();
}
#endif // SEARCHHELPER_H
