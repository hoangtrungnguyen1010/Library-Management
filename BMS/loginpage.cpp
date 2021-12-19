#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage_2::LoginPage_2(QWidget *parent) :
    QMainWindow(parent),
    login_ui(new Ui::LoginPage_2)
{
    login_ui->setupUi(this);
}

LoginPage_2::~LoginPage_2()
{
    delete login_ui;
}

void LoginPage_2::on_pushButton_clicked()
{
    hide();
    ui=new MainWindow(this);
    ui->show();
}

