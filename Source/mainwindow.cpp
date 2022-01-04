#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginpage.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// FUNCTION CLEARLY LAYOUT
void clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}


// CREATE AN VIEW LIST BOOK FRAME
QFrame* MainWindow::createViewListFrame(Book book){
    QFrame* res=new QFrame;
    res->setLayout(new QHBoxLayout);
    res->setFixedHeight(100);
    res->setMinimumWidth(500);
    res->setMaximumWidth(1000);
   res->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    res->setStyleSheet("background-color: #FEECE9");


    // Book image
    QLabel* lab=new QLabel;
    QString url = CURRENT_PATH.relativeFilePath("Resource/Images/"+book.getID());
    QPixmap pix(url);
    lab->setPixmap(pix);
    lab->setScaledContents(true);
    lab->setFixedWidth(75);

    // Book's name
    QLabel* name=new QLabel;
    name->setText(book.getName());
    name->setMinimumHeight(35);
    name->setStyleSheet("QLabel {font-size: 10pt;font-family: Agate Type}");
      name->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

      //Book's ID
      QLabel* id=new QLabel;
      id->setText(book.getID());
        id->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

      // Book's author
    QLabel* author=new QLabel;
    author->setText(book.getAuthor());
    author->setStyleSheet("QLabel{font:7pt italic}");
     author->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    QFrame* book_infor=new QFrame;
    book_infor->setLayout(new QVBoxLayout);
    book_infor->setFixedWidth(250);
    book_infor->layout()->addWidget(name);
    book_infor->layout()->addWidget(id);
    book_infor->layout()->addWidget(author);

    // Amount and tag
    QLabel* amount=new QLabel;
    amount->setText("Available: "+ QString::number(book.getNumOfRemaingBooks()));
    amount->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    QLabel* tag=new QLabel;
    tag->setText("#Tag: "+ book.getTag());
    tag->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    QFrame* amount_tag=new QFrame;
   amount_tag->setLayout(new QVBoxLayout);
   amount_tag->layout()->addWidget(amount);
   amount_tag->layout()->addWidget(tag);

    // Add to cart button

  QPushButton* add_to_cart_btn=new QPushButton;
   connect(add_to_cart_btn,&QPushButton::clicked,this,[book,this]{on_add_to_cart_btn_clicked(book);});
    QPixmap icon_img(":/WhiteIcons/Resource/White/shopping-cart.svg");
       add_to_cart_btn->setIcon(icon_img);
      add_to_cart_btn->setText("Add To Cart");
      add_to_cart_btn->setMaximumWidth(100);

      QString cs1="QPushButton {"
                     "background-color: orange;"
                     "color: rgb(0, 0, 0);"
                      "border-radius: 10px;"
                      "border: 2px solid red;"
                   "}"
                   "QPushButton:hover {"
                       "background-color: red;"
                   "}";
    add_to_cart_btn->setStyleSheet(cs1);


    QPushButton* borrow_btn=new QPushButton;
    connect(borrow_btn,&QPushButton::clicked,[book,this]{on_borrow_btn_clicked(book);});
    QPixmap borrow_img(":/WhiteIcons/Resource/White/plus-square.svg");
    borrow_btn->setIcon(borrow_img);
    borrow_btn->setText("Borrow       ");
    borrow_btn->setMaximumWidth(100);
    borrow_btn->setStyleSheet(cs1);

    QFrame* borrow_frame=new QFrame;
    borrow_frame->setLayout(new QVBoxLayout);
    borrow_frame->layout()->addWidget(borrow_btn);
    borrow_frame->layout()->addWidget(add_to_cart_btn);

    res->layout()->addWidget(lab);
    res->layout()->addWidget(book_infor);
     res->layout()->addWidget(amount_tag);
    res->layout()->addWidget(borrow_frame);

    return res;
}

//CREATE AN YOUR BOOK FRAME
QFrame* MainWindow::createYourBookFrame(Book book,QString time_start,int time_remaining){
    QFrame* res=new QFrame;
    res->setLayout(new QHBoxLayout);
    res->setFixedHeight(100);
    res->setMinimumWidth(500);
    res->setMaximumWidth(1000);
    res->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    res->setStyleSheet("background-color: #F0ECE3");


    // Book image
    QLabel* lab=new QLabel;
    QString url=CURRENT_PATH.relativeFilePath("Resource/Images/"+book.getID());
    QPixmap pix(url);
    lab->setPixmap(pix);
    lab->setScaledContents(true);
    lab->setFixedWidth(75);

    // Book's name
    QLabel* name=new QLabel;
    name->setText(book.getName());
    name->setMinimumHeight(35);
    name->setStyleSheet("QLabel {font-size: 15pt;font-family: Freestyle Script}");
      name->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);


     //Book's ID
     QLabel* id=new QLabel;
     id->setText(book.getID());
     id->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);


      // Book's author
    QLabel* author=new QLabel;
    author->setText(book.getAuthor());
    author->setStyleSheet("QLabel{font:7pt italic}");
     author->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    QFrame* book_infor=new QFrame;
    book_infor->setLayout(new QVBoxLayout);
    book_infor->setFixedWidth(250);
    book_infor->layout()->addWidget(name);
    book_infor->layout()->addWidget(id);
    book_infor->layout()->addWidget(author);

    // Start and remain
    QLabel* start=new QLabel;
    start->setText("Borrowed time: "+time_start);
    start->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
     qDebug()<<time_start;

    QLabel* remain=new QLabel;
    remain->setText("Remaining time: "+ QString::number(time_remaining));
    remain->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    QFrame* start_remain=new QFrame;
    start_remain->setLayout(new QVBoxLayout);
    start_remain->layout()->addWidget(start);
    start_remain->layout()->addWidget(remain);

    // CSS for button
    QString cs1="QPushButton {"
                   "background-color: orange;"
                   "color: rgb(0, 0, 0);"
                    "border-radius: 10px;"
                    "border: 2px solid red;"
                 "}"
                 "QPushButton:hover {"
                     "background-color: red;"
                 "}";

    // Return and extend button
     QPushButton* return_icon=new QPushButton;
     connect(return_icon,&QPushButton::clicked,this,[book,this]{on_return_btn_clicked(book);});
     QPixmap return_img(":/WhiteIcons/Resource/White/chevrons-left.svg");
     return_icon->setIcon(return_img);
     return_icon->setText("Return Book");
     return_icon->setStyleSheet(cs1);

     QPushButton* extend_icon=new QPushButton;
     connect(extend_icon,&QPushButton::clicked,this,[book,this]{on_extend_btn_clicked(book);});
      QPixmap extend_img(":/WhiteIcons/Resource/White/plus-circle.svg");
      extend_icon->setIcon(extend_img);
      extend_icon->setText("Extend time");
      extend_icon->setStyleSheet(cs1);

      QFrame* borrow_frame=new QFrame;
      borrow_frame->setLayout(new QVBoxLayout);
      borrow_frame->layout()->addWidget(extend_icon);
      borrow_frame->layout()->addWidget(return_icon);


    res->layout()->addWidget(lab);
    res->layout()->addWidget(book_infor);
    res->layout()->addWidget(start_remain);
    res->layout()->addWidget(borrow_frame);

    return res;

}

//CREATE AN CART FRAME
QFrame* MainWindow::createCartFrame(Book book)
{
    QFrame* res=new QFrame;
    res->setLayout(new QHBoxLayout);
    res->setFixedHeight(100);
    res->setMinimumWidth(500);
    res->setMaximumWidth(1000);
   res->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    res->setStyleSheet("background-color: #F0ECE3");


    // Book image
    QLabel* lab=new QLabel;
    QString url = CURRENT_PATH.relativeFilePath("Resource/Images/"+book.getID());
    QPixmap pix(url);
    lab->setPixmap(pix);
    lab->setScaledContents(true);
    lab->setFixedWidth(75);

    // Book's name
    QLabel* name=new QLabel;
    name->setText(book.getName());
    name->setMinimumHeight(35);
    name->setStyleSheet("QLabel {font-size: 15pt;font-family: Freestyle Script}");
      name->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

      //Book's ID
      QLabel* id=new QLabel;
      id->setText(book.getID());
        id->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

      // Book's author
    QLabel* author=new QLabel;
    author->setText(book.getAuthor());
    author->setStyleSheet("QLabel{font:7pt italic}");
     author->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    QFrame* book_infor=new QFrame;
    book_infor->setLayout(new QVBoxLayout);
    book_infor->setFixedWidth(250);
    book_infor->layout()->addWidget(name);
    book_infor->layout()->addWidget(id);
    book_infor->layout()->addWidget(author);

    // Amount and tag
    QLabel* amount=new QLabel;
    amount->setText("Available: "+ QString::number(book.getNumOfRemaingBooks()));
    amount->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    QLabel* tag=new QLabel;
    tag->setText("#Tag: "+ book.getTag());
    tag->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    QFrame* amount_tag=new QFrame;
   amount_tag->setLayout(new QVBoxLayout);
   amount_tag->layout()->addWidget(amount);
   amount_tag->layout()->addWidget(tag);

   // CSS for button
   QString cs1="QPushButton {"
                  "background-color: orange;"
                  "color: rgb(0, 0, 0);"
                   "border-radius: 10px;"
                   "border: 2px solid red;"
                "}"
                "QPushButton:hover {"
                    "background-color: red;"
                "}";

    // Add to cart button
   QPushButton* delete_btn=new QPushButton;
   connect(delete_btn,&QPushButton::clicked,this,[book,this]{on_delete_btn_cart_clicked(book);});
    QPixmap icon_img(":/WhiteIcons/Resource/White/minus-circle.svg");
       delete_btn->setIcon(icon_img);
      delete_btn->setText("Delete      ");
      delete_btn->setMaximumWidth(100);
      delete_btn->setStyleSheet(cs1);

      // Borrow button
      QPushButton* borrow_btn=new QPushButton;
      connect(borrow_btn,&QPushButton::clicked,[book,this]{on_borrow_btn_clicked(book);});
      QPixmap borrow_img(":/WhiteIcons/Resource/White/plus-square.svg");
      borrow_btn->setIcon(borrow_img);
      borrow_btn->setText("Borrow       ");
      borrow_btn->setMaximumWidth(100);
      borrow_btn->setStyleSheet(cs1);


    QFrame* borrow_frame=new QFrame;
    borrow_frame->setLayout(new QVBoxLayout);
    borrow_frame->layout()->addWidget(delete_btn);
    borrow_frame->layout()->addWidget(borrow_btn);

    res->layout()->addWidget(lab);
    res->layout()->addWidget(book_infor);
     res->layout()->addWidget(amount_tag);
    res->layout()->addWidget(borrow_frame);

    return res;
}


// ON VIEW BUTTON CLICKED
void MainWindow::on_view_btn_clicked()
{
    qDeleteAll(ui->frame->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
     delete ui->frame->layout();
    ui->frame->setLayout(new QVBoxLayout);

    ProxyLibraryDatabase* proxy=new ProxyLibraryDatabase ;
    // Head
    QFrame* head=new QFrame;
        QHBoxLayout *HLayout1=new QHBoxLayout;
        //Add book to library button
        QPushButton* add=new QPushButton;
         QPixmap add_img(":/WhiteIcons/Resource/White/file-plus.svg");
         connect(add,&QPushButton::clicked,this,&MainWindow::go_to_add_book_page);
         add->setIcon(add_img);
         add->setText("Add book");
         // Delete book to library button
         QPushButton* del=new QPushButton;
         QPixmap del_img(":/WhiteIcons/Resource/White/delete.svg");
         del->setIcon(del_img);
         del->setText("Delete book");
          connect(del,&QPushButton::clicked,this,&MainWindow::go_to_delete_page);
         // Check borrowed and damaged book

         QPushButton* check=new QPushButton;
         QPixmap check_img(":/WhiteIcons/Resource/White/check-square.svg");
         check->setIcon(check_img);
         check->setText("Check borrowed/damaged book");
         connect(check,&QPushButton::clicked,this,&MainWindow::on_check_borrowed_damaged_book_clicked);

         // Sort by name and id button
         QPushButton* sortByName_btn=new QPushButton;
         QPixmap sort_img(":/WhiteIcons/Resource/White/arrow-down.svg");
         sortByName_btn->setIcon(sort_img);
         sortByName_btn->setText("Sort By Name");
          connect(sortByName_btn,&QPushButton::clicked,this,&MainWindow::on_sort_by_name_btn_clicked);

         QPushButton* sortByID_btn=new QPushButton;
         sortByID_btn->setIcon(sort_img);
         sortByID_btn->setText("Sort By ID");
         connect(sortByID_btn,&QPushButton::clicked,this,&MainWindow::on_sort_by_id_btn_clicked);

         HLayout1->addWidget(add);
         HLayout1->addWidget(del);
         HLayout1->addWidget(check);

         QHBoxLayout* HLayout2= new QHBoxLayout;
         HLayout2->addWidget(sortByName_btn);
         HLayout2->addWidget(sortByID_btn);

         QVBoxLayout* layout=new QVBoxLayout;
         layout->addLayout(HLayout1);
         layout->addLayout(HLayout2);
         head->setLayout(layout);
         // CSS for button
         QString cs1="QPushButton {"
                        "background-color: orange;"
                        "color: rgb(0, 0, 0);"
                         "border-radius: 10px;"
                         "border: 2px solid red;"
                      "}"
                      "QPushButton:hover {"
                          "background-color: red;"
                      "}";
         head->setStyleSheet(cs1);

   ui->frame->layout()->addWidget(head);
  QVector<Book> lib=proxy->getListBook();
  int size=lib.size();
  qDebug()<<lib[0].getName();
  qDebug()<<lib[0].getNumOfRemaingBooks();
  for (int i=0;i<size;i++)
  {
      QFrame *a=createViewListFrame(lib[i]);
      ui->frame->layout()->addWidget(a);
      ui->frame->layout()->setAlignment(a,Qt::AlignTop);
  }
    ui->frame->layout()->setAlignment(Qt::AlignCenter);


    ui->MainFrame->setCurrentWidget(ui->ViewListBookPage);
    delete proxy;
}


void MainWindow::on_home_btn_clicked()
{
    ui->MainFrame->setCurrentWidget(ui->MainFramePage1);
}

// ON YOUR BOOK BUTTON
void MainWindow::on_your_book_btn_clicked()
{
   if(login_user){
       qDeleteAll(ui->frame_17->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
        delete ui->frame_17->layout();
       ui->frame_17->setLayout(new QVBoxLayout);

       QVector<Book> BorrowedList=login_user->getBorrowedBook();
       QVector<QDateTime> StartedTime=login_user->getStartedTime();

       int size=BorrowedList.size();
       qDebug()<<size;
       for (int i=0;i<size;i++){
           QFrame* a=createYourBookFrame(BorrowedList[i],StartedTime[i].toString(),login_user->getTimeRemainingBook(BorrowedList[i]));
           ui->frame_17->layout()->addWidget(a);
           ui->frame_17->layout()->setAlignment(a,Qt::AlignCenter);
       }
       ui->frame_17->layout()->setAlignment(Qt::AlignTop);

       ui->MainFrame->setCurrentWidget(ui->YourBook);
   }
   else {
       QMessageBox::information(this,"Message","You have no permisson to borrow !");
   }

}

// ON CART BUTTON
void MainWindow::on_cart_btn_clicked()
{
    if(login_user){
        qDeleteAll(ui->frame_18->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
        delete ui->frame_18->layout();
        ui->frame_18->setLayout(new QVBoxLayout);
        QVector<Book> CartList=login_user->getInCartBook();
        int size=CartList.size();
        for (int i=0;i<size;i++){
            QFrame* a=createCartFrame(CartList[i]);
            ui->frame_18->layout()->addWidget(a);
            ui->frame_18->layout()->setAlignment(a,Qt::AlignCenter);
        }
        ui->frame_18->layout()->setAlignment(Qt::AlignTop);
        ui->MainFrame->setCurrentWidget(ui->Cart);
    }
    else{
        QMessageBox::information(this,"Message","You have no permisson to borrow !");
    }

}


// ON SEARCH FINISHING
void MainWindow::on_lineEdit_3_editingFinished()
{
    qDeleteAll(ui->frame_211->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
     delete ui->frame_211->layout();
    ui->frame_211->setLayout(new QVBoxLayout);
    QString line=ui->lineEdit_3->text();
    ProxyLibraryDatabase* proxy=new ProxyLibraryDatabase;
    QVector<Book> searchByNameRes=proxy->findBookByName(line);
    QVector<Book> searchByIdRes=proxy->findBookByID(line);
    for(auto name:searchByNameRes){
        QFrame* a=createViewListFrame(name);
        ui->frame_211->layout()->addWidget(a);
        ui->frame_211->layout()->setAlignment(a,Qt::AlignTop);
    }
    for(int i=0;i<searchByIdRes.size();i++){
        QFrame* a=createViewListFrame(searchByIdRes[i]);
        ui->frame_211->layout()->addWidget(a);
        ui->frame_211->layout()->setAlignment(a,Qt::AlignTop);
    }
    ui->frame_21->layout()->setAlignment(Qt::AlignTop);
    ui->MainFrame->setCurrentWidget(ui->Search);
    delete proxy;
}

// ON LOG OUT BUTTON
void MainWindow::on_log_out_btn_clicked()
{
    if(QMessageBox::Yes==QMessageBox::question(this,"Log out","Do you want to log out ?")){
        if(login_user){
           login_user=nullptr;
        }
        else if(login_admin)
            login_admin=nullptr;
        }
        hide();
        LoginPage_2* login_ui=new LoginPage_2(this);
        login_ui->show();
}

// ON EXTEND TIME
void MainWindow::on_extend_btn_clicked(Book book)
{
     if(QMessageBox::Yes==QMessageBox::question(this,"Extend time","Do you want to extend borrowed time ?")){
         if(login_user->extendBorrowedTime(book))
         {
             QMessageBox::information(this,"Notification","Successfully extended time!");
             MainWindow::on_your_book_btn_clicked();
         }
         else{
             QMessageBox::information(this,"Notification","You already extended one time before!");
         }
     }
}

// ON BORROW BOOK BUTTON
void MainWindow::on_borrow_btn_clicked(Book book){
    if(login_user){
    if(QMessageBox::Yes==QMessageBox::question(this,"Borrow book","Do you want to borrow this book?")){
        if(login_user->borrowBook(book))
        { QMessageBox::information(this,"Borrow Book","This book has been borrowed successfully!");
        }
        else{
            QMessageBox::information(this,"Something's wrong","You can't borrow this book!");
        }
    }
    }
    else {
         QMessageBox::information(this,"Something's wrong","You are not user!");
    }

}
// ON RETURN BUTTON
void MainWindow::on_add_to_cart_btn_clicked(Book book){
    if(login_user){
        login_user->addToCart(book);
          QMessageBox::information(this,"Cart","This book has been added to your cart successfully!");
    }
    else{
         QMessageBox::information(this,"Something's wrong","You are not user!");
    }

}

//ON RETURN BUTTON BOOK
void MainWindow::on_return_btn_clicked(Book book){
     if(QMessageBox::Yes==QMessageBox::question(this,"Borrow book","Do you want to return this book?"))
     {
     clearLayout(ui->frame_17->layout());
     qDeleteAll(ui->frame_17->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
            login_user->returnBook(book);
            MainWindow::on_your_book_btn_clicked();
     }
}

// ON DELETE FROM CART
 void MainWindow::on_delete_btn_cart_clicked(Book book)
 {
     if(QMessageBox::Yes==QMessageBox::question(this,"Borrow book","Do you want to delete this book from your cart?"))
     {
     qDeleteAll(ui->frame_17->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
     delete ui->frame_17->layout();
     ui->frame_17->setLayout(new QVBoxLayout);
            login_user->deleteCartBook(book);
            MainWindow::on_cart_btn_clicked();
     }
 }

// ON EDIT PROFILE BUTTON
void MainWindow::on_edit_profile_btn_clicked()
{
    if(login_user){
        ui->name_edit->setText(login_user->showName());
        ui->id->setText((login_user->showID()));
        ui->address_edit->setText(login_user->showAddress());
        if(login_user->showGender()=="Male")
            ui->male_rad_btn->setChecked(true);
        else ui->female_rad_btn->setChecked(true);
        ui->username_lab->setText(login_user->showUsername());
        ui->pass_edit->setText(login_user->showPass());
        ui->MainFrame->setCurrentWidget(ui->editProfile);
    }
    else{
        ui->name_edit->setText(login_admin->showName());
        ui->id->setText((login_admin->showID()));
        ui->address_edit->setText(login_admin->showAddress());
        if(login_admin->showGender()=="Male")
            ui->male_rad_btn->setChecked(true);
        else ui->female_rad_btn->setChecked(true);
        ui->username_lab->setText(login_admin->showUsername());
        ui->pass_edit->setText(login_admin->showPass());
        ui->MainFrame->setCurrentWidget(ui->editProfile);
    }
}

// ON SAVE INFORMATION BUTTON
void MainWindow::on_save_btn_clicked()
{
    HumanDatabase* humanDtb=HumanDatabase::getInstance();
    if (login_user){
                if(QMessageBox::Yes==QMessageBox::question(this,"Save information","Do you want to save information ?")){
                     login_user->editName(ui->name_edit->text());
                     login_user->editAddress(ui->address_edit->text());
                     login_user->editGender(ui->female_rad_btn->isChecked());
                     login_user->editPass(ui->pass_edit->text());
                     humanDtb->editName(login_user->showID(),ui->name_edit->text());
                     humanDtb->editAddress(login_user->showID(),ui->address_edit->text());
                     humanDtb->editGender(login_user->showID(),ui->female_rad_btn->isChecked());
                     humanDtb->editPass(login_user->showID(),ui->pass_edit->text());
                     qDebug()<<humanDtb->getListUser()[3]->showPass();
                     MainWindow::on_edit_profile_btn_clicked();
                }
            }
            else {
                if(QMessageBox::Yes==QMessageBox::question(this,"Save information","Do you want to save information ?")){
                    login_admin->editName(ui->name_edit->text());
                    login_admin->editAddress(ui->address_edit->text());
                    qDebug()<<login_admin->showAddress();
                    login_admin->editGender(ui->female_rad_btn->isChecked());
                    login_admin->editPass(ui->pass_edit->text());
                    humanDtb->editName(login_admin->showID(),ui->name_edit->text());
                    humanDtb->editAddress(login_admin->showID(),ui->address_edit->text());
                    humanDtb->editGender(login_admin->showID(),ui->female_rad_btn->isChecked());
                    humanDtb->editPass(login_admin->showID(),ui->pass_edit->text());
                    MainWindow::on_edit_profile_btn_clicked();
                }
            }
}

// ON VIEW USER'S INFORMATION BUTTON
void MainWindow::on_user_btn_clicked()
{
    if(login_user)
        QMessageBox::information(this,"Notification","Only admin can view user list!");
    else{
        QHeaderView *header = ui->tableWidget->horizontalHeader();
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        header->setSectionResizeMode(QHeaderView::Stretch);
        HumanDatabase* humandtb=HumanDatabase::getInstance();
        QVector<User*> userData=humandtb->getListUser();
        int rowCount=userData.size();
        ui->tableWidget->setRowCount(rowCount);
        for(int i=0;i<rowCount;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(userData[i]->showName()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(userData[i]->showID()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(userData[i]->showGender()));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(userData[i]->showAddress()));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(userData[i]->BorrowedBookToString()));
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(userData[i]->ExpiredBookToString()));
        }
        ui->MainFrame->setCurrentWidget(ui->User);
    }
}

// ON VIEW MORE BUTTON
void MainWindow::on_ViewMoreBtn_clicked()
{
    MainWindow::on_view_btn_clicked();
}

// ON GO TO ADD BOOK PAGE
void MainWindow::go_to_add_book_page()
{
    ui->MainFrame->setCurrentWidget(ui->Add);
}

// ON GO TO DELETE PAGE
void MainWindow::go_to_delete_page()
{
    ui->MainFrame->setCurrentWidget(ui->Delete);
}

// ON SORT BY NAME BUTTON
void MainWindow::on_sort_by_name_btn_clicked()
{
    ProxyLibraryDatabase* proxy=new ProxyLibraryDatabase;
    proxy->sortByName();
    MainWindow::on_view_btn_clicked();
    delete proxy;
}

// ON SORT BY ID BUTTON
void MainWindow::on_sort_by_id_btn_clicked()
{
    ProxyLibraryDatabase* proxy=new ProxyLibraryDatabase;
    proxy->sortByID();
    MainWindow::on_view_btn_clicked();
     delete proxy;
}

// ON CHECK BORROWED AND DAMAGED BOOK
void MainWindow::on_check_borrowed_damaged_book_clicked()
{

    if(login_user){
        QMessageBox::information(this,"Notification","Only admin can use it!");
        return;
    }
     ProxyLibraryDatabase* proxy;
     proxy=new ProxyLibraryDatabase(1);
     QHeaderView *header = ui->book_table->horizontalHeader();
     ui->book_table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
     header->setSectionResizeMode(QHeaderView::Stretch);
     QVector<Book> list=proxy->getListBook();
     int rowCount=list.size();
     ui->book_table->setRowCount(rowCount);
     for(int i=0;i<rowCount;i++)
      {
              ui->book_table->setItem(i,0,new QTableWidgetItem(list[i].getID()));
              ui->book_table->setItem(i,1,new QTableWidgetItem(list[i].getName()));
              ui->book_table->setItem(i,2,new QTableWidgetItem(QString::number(proxy->getQuantity(list[i].getID()))));
              ui->book_table->setItem(i,3,new QTableWidgetItem(QString::number(proxy->getBorrowed(list[i].getID()))));
              qDebug()<<list[i].getNumOfOfBorrowedBooks();
              ui->book_table->setItem(i,4,new QTableWidgetItem(QString::number(proxy->getDamaged(list[i].getID()))));
      }
        ui->MainFrame->setCurrentWidget(ui->BookInfor);
         delete proxy;
}
// ADD DIRECTORY OF BOOK'S COVER
void MainWindow::on_add_directory_btn_clicked()
{
    QString filter = "All File (*.*) ;; Image File (*.jpg;*.png)";
    QString fileName = QFileDialog::getOpenFileName(this, "Add book's cover", QDir::homePath(), filter); // path cua file anh
    ui->addDirectory->setText(fileName);
    QStringList path = fileName.split("/");
    QString name = path[path.size()-1];
    QDir dir = QDir::currentPath();
    QString ImgPath = dir.relativeFilePath("Resource/Images/"+name); // path hien tai project
    if (QFile::exists(ImgPath))
    {
        QFile::remove(ImgPath);
    }

    if (QFile::copy(fileName, ImgPath))
        QMessageBox::information(this, "Notification", "Add book's cover successfully!");
}
// ON ADD BUTTON IN ADD BOOK PAGE
void MainWindow::on_add_book_btn_clicked()
{
    ui->MainFrame->setCurrentWidget(ui->Add);
    QString title, id, author, publisher, tag;
    int quantity;
    title=ui->addTitle->text();
    id=ui->addISBN->text();
    author=ui->addAuthor->text();
    publisher=ui->addPublisher->text();
    tag=ui->addTag->text();
    quantity=ui->addQuantity->text().toInt();
    qDebug()<<title<<id<<author<<publisher<<tag<<quantity;
    ProxyLibraryDatabase* proxy;
    if(login_user){
       proxy =new ProxyLibraryDatabase(0);
    }
    else
        proxy=new ProxyLibraryDatabase(1) ;
    bool check = false; // true: already have this book
    for (auto book:proxy->getListBook()){
        if (QString::compare(book.getID(), id)==0){
            check = true;
        }
    }
    if (check&&proxy->addBook(id,quantity)){
        QMessageBox::information(this, "Notification", "Add book successfully!");
    }
    else if(!check&&proxy->addBook(id, title, author, publisher, tag, quantity)){
        QDir dir = QDir::currentPath();
        QString path_res = dir.relativeFilePath("Resource/Images/"+id); // path cua anh ket qua
        QString name = ui->addDirectory->text();
        QStringList path = name.split("/");
        QString gotName = path[path.size()-1];
        QString path_prev = dir.relativeFilePath("Resource/Images/"+gotName);
        if (QString::compare(path_res, path_prev)!=0){
            QFile::copy(path_prev, path_res);
        }
        QMessageBox::information(this, "Notification", "Add book successfully!");
    }
    else
        QMessageBox::information(this, "Notification", "Only admin can add book!");
     delete proxy;
}

// ON DELETE BUTTON IN DELETE BOOK PAGE
void MainWindow::on_delete_book_btn_clicked()
{
    ui->MainFrame->setCurrentWidget(ui->Delete);
    QString title, id;
    title=ui->deleteTitle->text();
    id=ui->deleteISBN->text();
    qDebug()<<title<<id;
    ProxyLibraryDatabase* proxy;
    if(login_user){
       proxy =new ProxyLibraryDatabase(0);
    }
    else
        proxy=new ProxyLibraryDatabase(1) ;
    bool check = false; // true: Library has this book.
    for (auto book:proxy->getListBook()){
        qDebug()<<book.getID();
         qDebug()<<book.getName();
        if (book.getID()==id && book.getName()==title)
        {
            check = true;
            break;
        }
    }
    if (!check) {
        QMessageBox::information(this, "Notification", "Our library does not have this book!");
        return;
    }

    if (ui->deleteAll->isChecked()){
        if(proxy->deleteBook(id)){
            QString notif = QString("Successfully delete all of books \n with title \"%1\" and ISBN: %2").arg(title).arg(id);
            QMessageBox::information(this, "Notification", notif);
        }
        else{
            QMessageBox::information(this,"Notification","There are still borrowed book!");
        }
    }
    else if (ui->deleteNumber->isChecked()){
        int quantity;
        quantity = ui->numberDelete->text().toInt();
        proxy->deleteBook(id, quantity);
        QString notif = QString("Successfully delete %1 book(s) \n with title \"%2\" and ISBN: %3").arg(quantity).arg(title).arg(id);
        QMessageBox::information(this, "Notification", notif);
    }
    else {
        QMessageBox::information(this, "Notification", "Please choose the number of books you want to delete!");
    }
     delete proxy;
}

// ON CANCEL BUTTON IN ADD BOOK PAGE
void MainWindow::on_cancel_add_book_btn_clicked()
{
    ui->MainFrame->setCurrentWidget(ui->MainFramePage1);
}

// ON CANCEL BUTTON IN DELETE BOOK PAGE
void MainWindow::on_cancel_delete_book_btn_clicked()
{
    ui->MainFrame->setCurrentWidget(ui->MainFramePage1);
}

// ON SAVE BOOK INFORMATION BUTTON
void MainWindow::on_book_saved_clicked()
{
    ProxyLibraryDatabase* proxy=new ProxyLibraryDatabase(1);
    int rowCount=ui->book_table->rowCount();
    for(int i=0;i<rowCount;i++){
        QString ID=proxy->getListBook()[i].getID();
        qDebug()<<ID;
        int quatity_num=ui->book_table->item(i,2)->text().toInt();
        int damaged_num=ui->book_table->item(i,4)->text().toInt();
        proxy->updateQuantity(ID,quatity_num);
        proxy->updateDamaged(ID,damaged_num);
    }
    QMessageBox::information(this,"Notification","Update information successfully!");
    delete proxy;
    MainWindow::on_check_borrowed_damaged_book_clicked();
}

void MainWindow::closeEvent(QCloseEvent *event)
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

void MainWindow::showEvent(QShowEvent* event)
{
    if(login_user){
            QList<QString> name=login_user->showName().split(' ');
            QString lastName=name[name.size()-2]+" "+name[name.size()-1];
          ui->Fullname->setText(lastName);
    }

    else {
        QList<QString> name=login_admin->showName().split(' ');
        QString lastName=name[name.size()-2]+" "+name[name.size()-1];
        ui->Fullname->setText(lastName);
       }
}


