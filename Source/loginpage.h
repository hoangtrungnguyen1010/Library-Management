#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include <QMainWindow>
#include <mainwindow.h>
#include <QtGui/QIcon>
#include "HumanDatabase.h"
extern User* login_user;
extern Admin* login_admin;

namespace Ui {

class LoginPage_2;
}
class LoginPage_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginPage_2(QWidget *parent = nullptr);
    ~LoginPage_2();

private slots:

       void on_pushButton_clicked();

       void on_pushButton_2_clicked();

       void on_pushButton_4_clicked();

       void on_pushButton_5_clicked();

       void on_pushButton_3_clicked();

       void on_pushButton_7_clicked();

       void on_pushButton_6_clicked();

private:
    QCloseEvent* close_event;
public:
    void closeEvent(QCloseEvent* event);
private:
    Ui::LoginPage_2 *login_ui;
    MainWindow *ui;
};

#endif // LOGINPAGE_H
