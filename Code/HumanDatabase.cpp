#include<HumanDatabase.h>

void HumanDatabase::loadDTB(RealLibraryDatabase* Lib){
    QFile file(_fileName);

    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "File not open" << file.error();
    }else{
       qDebug() << "File is open";
    }

    QTextStream in(&file);
    while(!in.atEnd()){

        QString accountInfor=in.readLine();
        QStringList info = accountInfor.split("|");

        if (info.size()<6) continue;
        if(QString::compare(info[6],"Admin")==0){
            Admin ad(info[0],info[1],info[2].toInt(),info[3],info[4], info[5]);
            this->AdData.push_back(ad);
        }
        else if(QString::compare(info[6],"User")==0 || QString::compare(info[6],"Vip User")==0){
            User* user;
            if (info[6]=="User"){
                user = new User(info[0],info[1],info[2].toInt(),info[3],info[4], info[5]);
            }
            else {
                user = new VipUser(info[0],info[1],info[2].toInt(),info[3],info[4], info[5]);
            }

            int i=7;
            if (i>=info.size()) continue;

            //Add books in the cart
            while(info[i][0]=='c'){
                QString string=info[i];
                QStringList templist=string.split(",");
                Book temp;

                if (Lib->findBookByID(templist[1], temp)){
                    user->addToCart(temp);

                }
                i++;
            }
            if (i>=info.size()) continue;

            //Add books borrowed
            while( info[i][0]=='b'){

                QString string=info[i];
                QStringList templist=string.split(",");
                Book temp;
                if (Lib->findBookByID(templist[1], temp)){
                    user->borrowBook(temp, info[++i].toInt(), info[++i]);
                }
                i++;
                if (i>=info.size()) break;
            }
            this->UserData.push_back(user);
       }
    }
    file.close();
}

void HumanDatabase::printDTB(){
    int AdSize;
    AdSize=this->AdData.size();

    int UsSize;
    UsSize=this->UserData.size();

    for(int i=0; i<AdSize;i++){
        qDebug()<<this->AdData[i].toString();
        qDebug()<<"\n";
    }

    for(int i=0;i<UsSize;i++){
        qDebug()<<this->UserData[i]->toString();
        qDebug()<<"\n";
    }
}

void HumanDatabase::saveDTB(){
    int AdSize=this->AdData.size();
    int UsSize=this->UserData.size();

    QFile file(_fileName);
    if ( file.open(QIODevice::WriteOnly) )
    {
        QTextStream stream( &file );
        for(int i=0; i<AdSize;i++){
            stream <<this->AdData[i].toString();
            stream <<"\n";
        }

        for(int i=0;i<UsSize;i++){
            stream <<this->UserData[i]->toString();
            stream <<"\n";
        }
    }
    file.close();
}

bool HumanDatabase::addNewUser(QString id, QString name, bool gender, QString address, QString username, QString password, QString type){
    User* add;

    int UserSize= this->UserData.size();
    for(int i=0;i<UserSize;i++){
        if (this->UserData[i]->checkIsID(id) || this->UserData[i]->checkIsUsername(username)){
            return 0;
        }
    }
    if (type == "User"){
        add = new User(id, name, gender, address, username, password);
    }
    if (type == "Vip User"){
        add = new VipUser(id, name, gender, address, username, password);
    }
    this->UserData.push_back(add);
    return 1;
}

bool HumanDatabase::addNewAdmin(QString id, QString name, bool gender, QString address, QString username, QString password){
    int AdSize = this->AdData.size();
    for (int i=0;i<AdSize;i++){
        if (this->UserData[i]->checkIsID(id)){
            return 0;
        }
    }
    Admin add(id, name, gender, address, username, password);
    this->AdData.push_back(add);
    return 1;
}

User* HumanDatabase::getUser(QString username, QString password){
    int size= this->UserData.size();
    for (int i=0;i<size;i++){
        if (UserData[i]->checkIsUsername(username) && UserData[i]->checkIsPassword(password) ){
            return UserData[i];
        }
    }
    return NULL;
}


HumanDatabase::~HumanDatabase(){
    this->saveDTB();
    int size= this->UserData.size();

    for(int i=0;i<size;i++){
        delete this->UserData[i];
    }
}
