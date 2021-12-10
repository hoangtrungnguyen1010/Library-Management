#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Submit_clicked()
{
    QString user,pass;
   user=ui->lineEdit_2->text();
   pass=ui->lineEdit->text();
   qDebug()<<user<<pass;
   QFile file("D:/BMS/account.txt");
   file.open(QIODevice::ReadOnly);
   QTextStream in(&file);
   int f=0;
   while(!in.atEnd()){
       QString saved_account=in.readLine();
       QStringList info = saved_account.split(";");
       //QString saved_pass=in.readLine();
       if(QString::compare(user,info[0])==0 && QString::compare(pass,info[1])==0){
           //QMessageBox::information(this,"Login success.", "You have successfully logged in!");
           f=1;
           ui->stackedWidget->setCurrentIndex(1);
           break;
       }

   }
   if(f==0){
        QMessageBox::information(this,"Login failed.", "Try again!");
   }

}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    LibraryDatabase data;
    data.uploadBook();
    QString list=data.viewListBook();
    qDebug()<<list;
    ui->textEdit->setText(list);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

