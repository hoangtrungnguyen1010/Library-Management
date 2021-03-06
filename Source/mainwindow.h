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
#include <QSignalMapper>
#include <QTableWidget>
#include <QHeaderView>
#include <QDir>
#include <QFileDialog>
#include <QCloseEvent>
#include <QEvent>
#include <QShowEvent>
#include "Book.h"
#include "LibraryDatabase.h"
#include "RealLibraryDatabase.h"
#include "ProxyLibraryDataBase.h"
#include "Person.h"
#include "User.h"
#include "Admin.h"
extern const QDir CURRENT_PATH;
extern User* login_user;
extern Admin* login_admin;

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
    QFrame* createCartFrame(Book book);
private slots:


    void on_view_btn_clicked();
    void on_home_btn_clicked();
    void on_your_book_btn_clicked();
    void on_cart_btn_clicked();
     void on_user_btn_clicked();



    void on_add_to_cart_btn_clicked(Book book);
    void on_borrow_btn_clicked(Book book);
    void on_return_btn_clicked(Book book);
    void on_extend_btn_clicked(Book book);
    void on_delete_btn_cart_clicked(Book book);
    void go_to_add_book_page();
    void go_to_delete_page();
    void on_sort_by_name_btn_clicked();
    void on_sort_by_id_btn_clicked();
    void on_check_borrowed_damaged_book_clicked();



    void on_lineEdit_3_editingFinished();

    void on_log_out_btn_clicked();

    void on_edit_profile_btn_clicked();

    void on_save_btn_clicked();





    void on_ViewMoreBtn_clicked();

    void on_add_book_btn_clicked();

    void on_delete_book_btn_clicked();

    void on_cancel_add_book_btn_clicked();

    void on_add_directory_btn_clicked();

    void on_cancel_delete_book_btn_clicked();


    void on_book_saved_clicked();

private:
    QCloseEvent* close_event;
    QShowEvent* show_event;
public:
    void closeEvent(QCloseEvent* event);
    void showEvent(QShowEvent* event);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
