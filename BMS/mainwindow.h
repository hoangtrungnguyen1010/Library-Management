#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QStringList>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QLayout>
#include "Book.h"
#include "LibraryDatabase.h"
#include "RealLibraryDatabase.h"
#include "Person.h"
#include "Button.h"
#include "User.h"

extern User* login_user;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QFrame* createViewListFrame(Book book);
    QFrame* createYourBookFrame(Book book,QString time_start,int time_remaining);
private slots:


    void on_view_btn_clicked();

    void on_home_btn_clicked();
    void on_add_to_cart_btn_clicked();


    void on_return_btn_clicked();
    void on_extend_btn_clicked();



    void on_your_book_btn_clicked();

private:
    Ui::MainWindow *ui;
    AddToCartBtn* add_to_cart_btn;
};
#endif // MAINWINDOW_H
