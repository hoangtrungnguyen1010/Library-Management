#ifndef LOGINPAGE_H
#define LOGINPAGE_H

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
    explicit LoginPage_2(QWidget *parent = nullptr);
    ~LoginPage_2();

private slots:

    void on_pushButton_clicked();

private:
    Ui::LoginPage_2 *login_ui;
    MainWindow *ui;
};

#endif // LOGINPAGE_H
