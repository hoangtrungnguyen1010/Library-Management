#include<HumanDatabase.h>

void HumanDatabase::loadDTB(){
    QFile file("..//Project/account.txt");

    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "File not open" << file.error();
    }else{
       qDebug() << "File is open";
    }

    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);
    while(!in.atEnd()){
        QString accountInfor=in.readLine();
        QStringList info = accountInfor.split("|");
        qDebug()<<info.size();
        qDebug()<<accountInfor;
//        if (info.size()!=6) break;
        if(QString::compare(info[5],"Admin")==0){
            Admin ad(info[0],info[2],info[3],info[4],info[0], info[1]);
            qDebug()<<ad.showInfor()<<endl;
            this->AdData.push_back(ad);
        }
        else if(QString::compare(info[5],"User")==0){
            User  user(info[0],info[2],info[3],info[4],info[0], info[1]);
            this->UserData.push_back(user);
        }
    }
}

void HumanDatabase::printDTB(){
    int AdSize;
    AdSize=this->AdData.size();
    int UsSize;
    UsSize=this->UserData.size();

    for(int i=0; i<AdSize;i++){
        qDebug()<<this->AdData[i].showInfor();
        qDebug()<<"\n";
    }

    for(int i=0;i<UsSize;i++){
        qDebug()<<this->UserData[i].showInfor();
        qDebug()<<"\n";
    }
}

