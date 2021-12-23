#ifndef LOGINPAGE_H
#define LOGINPAGE_H
#include<HumanDatabase.h>
#include <QDialog>
#include <QMainWindow>
#include <mainwindow.h>
namespace Ui {
class LoginPage_2;
}
class LoginPage_2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit LoginPage_2(QWidget *parent = nullptr, HumanDatabase* dtb = nullptr);
    ~LoginPage_2();

private slots:

    User* on_pushButton_clicked();

private:
    HumanDatabase* dtb;
    Ui::LoginPage_2 *login_ui;
    MainWindow *ui;
};

#endif // LOGINPAGE_H
