#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage_2::LoginPage_2(QWidget *parent, HumanDatabase* dtb) :
    QMainWindow(parent),
    login_ui(new Ui::LoginPage_2),
    ui(new MainWindow)
{
    login_ui->setupUi(this);
    this->dtb= dtb;
}

LoginPage_2::~LoginPage_2()
{
    delete login_ui;
}

User* LoginPage_2::on_pushButton_clicked()
{
    QString username = login_ui->lineEdit->text();
    QString password = login_ui->lineEdit_2->text();
    User* user = dtb->getUser(username, password);
    if (user) {
        ui->show();
        hide();
    }
    return user;
}

