#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage_2::LoginPage_2(QWidget *parent) :
    QMainWindow(parent),
    login_ui(new Ui::LoginPage_2),
    ui(new MainWindow)
{
    login_ui->setupUi(this);
}

LoginPage_2::~LoginPage_2()
{
    delete login_ui;
}

void LoginPage_2::on_pushButton_clicked()
{
        QString user,pass;
        user=login_ui->lineEdit->text();
        pass=login_ui->lineEdit_2->text();
        qDebug()<<user<<pass;
      HumanDatabase* humanDtb=HumanDatabase::getInstance();
      login_user=humanDtb->findSavedAccount(user,pass);
      if(login_user!=nullptr){
          hide();
          ui=new MainWindow(this);
          ui->show();
      }
      else{
           QMessageBox::information(this,"Login failed.", "Wrong password. Try again!");
      }

}
void LoginPage_2::on_pushButton_2_clicked()
{
    login_ui->stackedWidget_2->setCurrentIndex(1);
}


void LoginPage_2::on_pushButton_5_clicked()
{
    login_ui->stackedWidget_2->setCurrentIndex(0);
}


void LoginPage_2::on_pushButton_4_clicked()
{
    QString name,gender,id,address,username,pass,retypepass;
    name=login_ui->fullName->text();
    gender=login_ui->gender->text();
    id=login_ui->id->text();
    address=login_ui->address->text();
    username=login_ui->username->text();
    pass=login_ui->newpassword->text();
    retypepass=login_ui->retypepassword->text();
    qDebug()<<name<<gender<<id<<address<<username<<pass<<retypepass;
    if(QString::compare(pass, retypepass)==0){
        QFile file("D:/BMS1/Resource/Data/temp.txt");
        file.open(QIODevice::ReadOnly);
        QTextStream out(&file);
        int f=0;
        while(!out.atEnd()){
           QString saved_account=out.readLine();
           QStringList info = saved_account.split("|");
           //QString saved_pass=in.readLine();
           if(QString::compare(username,info[4])==0){
               QMessageBox::information(this,"Register failed.", "This username is already taken. Try again!");
               f=1;
               break;
           }
        }
        file.close();
        if (f==0){
            QFile file2("D:/BMS1/Resource/Data/UserData.txt");
            file2.open(QIODevice::Append);
            QTextStream out(&file2);
            out << id << "|" << name << "|" << gender << "|" << address << "|" << username << "|" << pass << "\n";
            QMessageBox::information(this,"Notification", "Register successfully!");
            file2.close();
        }
    }
    else {
        QMessageBox::information(this,"Login failed.", "The password and retype password do not match. Try again!");
    }
}


void LoginPage_2::on_pushButton_3_clicked()
{
    login_ui->stackedWidget_2->setCurrentIndex(2);
}


void LoginPage_2::on_pushButton_7_clicked()
{
    login_ui->stackedWidget_2->setCurrentIndex(0);
}


void LoginPage_2::on_pushButton_6_clicked()
{
    QString name,gender,username,id,address;
    name=login_ui->fullName_2->text();
    gender=login_ui->gender_2->text();
    id=login_ui->id_2->text();
    address=login_ui->address_2->text();
    username=login_ui->username_2->text();
    qDebug()<<name<<gender<<username<<id<<address;
    QFile file("D:/BMS1/Resource/Data/UserData.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream out(&file);
    int f=0;
    while(!out.atEnd()){
       QString saved_account=out.readLine();
       QStringList info = saved_account.split("|");
       if(QString::compare(id,info[0])==0 && QString::compare(name,info[1])==0 && QString::compare(gender,info[2])==0 &&
               QString::compare(address,info[3])==0 && QString::compare(username,info[4])==0){
           QString notif = QString("Your password is %1").arg(info[5]);
           QMessageBox::information(this,"Notification", notif);
           f=1;
           break;
       }
    }
    file.close();
    if (f==0){
        QMessageBox::information(this,"Notification", "Wrong information. Try again!");
    }
}


