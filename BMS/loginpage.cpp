#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage_2::LoginPage_2(QWidget *parent) :
    QMainWindow(parent),
    login_ui(new Ui::LoginPage_2),
    ui(new MainWindow)
{
    login_ui->setupUi(this);
    login_ui->loginUser->setChecked(true);
}

LoginPage_2::~LoginPage_2()
{
    delete login_ui;
}

void LoginPage_2::on_pushButton_clicked()
{
    QString user,pass;
    int type;
    user=login_ui->lineEdit->text();
    pass=login_ui->lineEdit_2->text();
    if (login_ui->loginUser->isChecked()){
        type = 1;
    }
    else if (login_ui->loginAdmin->isChecked()){
        type = 2;
    }
    else {
        QMessageBox::information(this, "Notification", "Please choose type of your account!");
        return;
    }
    qDebug()<<user<<pass<<type;

    if (type == 1){
        login_admin=nullptr;
        HumanDatabase* humanDtb=HumanDatabase::getInstance();
        login_user = humanDtb->findSavedUser(user,pass);
        if(login_user!=nullptr){
          hide();
          ui=new MainWindow(this);
          ui->show();
        }
        else{
           QMessageBox::information(this,"Login failed.", "User name not found or incorrect password. Try again!");
        }
    }
    if (type == 2){
        login_user=nullptr;
        HumanDatabase* humanDtb=HumanDatabase::getInstance();
        login_admin = humanDtb->findSavedAdmin(user,pass);
        if(login_admin!=nullptr){
          hide();
          ui=new MainWindow(this);
          QIcon icon(":/Images/Resource/Images/icon.png");
          ui->setWindowIcon(icon);
          ui->show();
        }
        else{
           QMessageBox::information(this,"Login failed.", "User name not found or incorrect password. Try again!");
        }
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
    QString name,id,address,username,pass,retypepass;
    bool gender;
    name=login_ui->fullName->text();
    //gender=login_ui->gender->text();
    id=login_ui->id->text();
    address=login_ui->address->text();
    username=login_ui->username->text();
    pass=login_ui->newpassword->text();
    retypepass=login_ui->retypepassword->text();
    if (login_ui->maleCheck->isChecked()){
        gender = false;
    }
    else if (login_ui->femaleCheck->isChecked()){
        gender = true;
    }
    else {
        QMessageBox::information(this, "Notification", "Please check your gender!");
        return;
    }
    qDebug()<<name<<gender<<id<<address<<username<<pass<<retypepass;
    HumanDatabase* humanDtb=HumanDatabase::getInstance();
    if(QString::compare(pass, retypepass)==0){
        // kiem tra username da co chua
        int f = 0;
        if (humanDtb->checkExisted(username)){
            QMessageBox::information(this,"Register failed.", "This username is already taken. Try again!");
            f = 1;
        }    
        if (f==0){
            if (login_ui->userCheck->isChecked()){
                // add user moi
                humanDtb->addNewUser(id, name, gender, address, username, pass, "User");
                humanDtb->saveDTB();
                QMessageBox::information(this,"Notification", "Register successfully!");
            }
            else if (login_ui->vipuserCheck->isChecked()){
                humanDtb->addNewUser(id, name, gender, address, username, pass, "Vip User");
                humanDtb->saveDTB();
                QMessageBox::information(this,"Notification", "Register successfully!");
                login_ui->stackedWidget_2->setCurrentWidget(login_ui->stackedWidget_2Page1);
            }
            else {
                QMessageBox::information(this, "Notification", "Please check type of account!");
            }
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
    QString name,username,id,address;
    QString gender;
    name=login_ui->fullName_2->text();
//    gender=login_ui->gender_2->text();
    id=login_ui->id_2->text();
    address=login_ui->address_2->text();
    username=login_ui->username_2->text();
    if (login_ui->maleCheck_2->isChecked()){
        gender = "Male";
    }
    else if (login_ui->femaleCheck_2->isChecked()){
        gender = "Female";
    }
    else{
        QMessageBox::information(this, "Notification", "Please check your gender!");
               return;
    }
    qDebug()<<name<<gender<<username<<id<<address;
    HumanDatabase* humanDtb=HumanDatabase::getInstance();
    bool flag = false;
    for (auto user:humanDtb->UserData){
        if (QString::compare(id, user->showID())==0 && QString::compare(name, user->showName())==0 &&
            QString::compare(address, user->showAddress())==0 && QString::compare(username, user->showUsername())==0&&QString::compare(gender, user->showGender())==0)
        {
               QString notif = QString("Your password is %1").arg(user->showPass());
               QMessageBox::information(this,"Notification", notif);
               flag = true;
               break;
        }
    if (!flag){
        QMessageBox::information(this,"Notification", "Wrong information. Try again!");
    }
}
}

 void LoginPage_2::closeEvent(QCloseEvent* event)
 {
     QMessageBox::StandardButton answer = QMessageBox::question(
                     this,
                     tr("Close the Window"),
                     tr("Do you want to close the window?"),
                     QMessageBox::Yes | QMessageBox::No);

         if(answer == QMessageBox::Yes){
             HumanDatabase::getInstance()->saveDTB();
             RealLibraryDatabase::getInstance()->sortByID();
             RealLibraryDatabase::getInstance()->saveDTB();
             event->accept();
         }
         else
             event->ignore();
 }

