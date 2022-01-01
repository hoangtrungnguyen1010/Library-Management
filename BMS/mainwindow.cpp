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



// CREATE AN VIEW LIST BOOK FRAME
QFrame* MainWindow::createViewListFrame(Book* book){
    QFrame* res=new QFrame;
    res->setLayout(new QHBoxLayout);
    res->setFixedHeight(100);
    res->setMinimumWidth(500);
    res->setMaximumWidth(1000);
   res->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    res->setStyleSheet("background-color: #FEECE9");


    // Book image
    QLabel* lab=new QLabel;
    QString url=":/Images/Resource/Images/"+book->getID();
    QPixmap pix(url);
    lab->setPixmap(pix);
    lab->setScaledContents(true);
    lab->setFixedWidth(75);

    // Book's name
    QLabel* name=new QLabel;
    name->setText(book->getName());
    name->setMinimumHeight(35);
    name->setStyleSheet("QLabel {font-size: 15pt;font-family: Freestyle Script}");
      name->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

      //Book's ID
      QLabel* id=new QLabel;
      id->setText(book->getID());
        id->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

      // Book's author
    QLabel* author=new QLabel;
    author->setText(book->getAuthor());
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
    amount->setText("Amount: "+ QString::number(book->getNumOfRemaingBooks()));
    amount->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    QLabel* tag=new QLabel;
    tag->setText("#Tag: "+ book->getTag());
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
QFrame* MainWindow::createYourBookFrame(Book* book,QString time_start,int time_remaining){
    QFrame* res=new QFrame;
    res->setLayout(new QHBoxLayout);
    res->setFixedHeight(100);
    res->setMinimumWidth(500);
    res->setMaximumWidth(1000);
    res->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    res->setStyleSheet("background-color: #F0ECE3");


    // Book image
    QLabel* lab=new QLabel;
    QString url=":/Images/Resource/Images/"+book->getID();
    QPixmap pix(url);
    lab->setPixmap(pix);
    lab->setScaledContents(true);
    lab->setFixedWidth(75);

    // Book's name
    QLabel* name=new QLabel;
    name->setText(book->getName());
    name->setMinimumHeight(35);
    name->setStyleSheet("QLabel {font-size: 15pt;font-family: Freestyle Script}");
      name->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);


     //Book's ID
     QLabel* id=new QLabel;
     id->setText(book->getID());
     id->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);


      // Book's author
    QLabel* author=new QLabel;
    author->setText(book->getAuthor());
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
QFrame* MainWindow::createCartFrame(Book* book)
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
    QString url=":/Images/Resource/Images/"+book->getID();
    QPixmap pix(url);
    lab->setPixmap(pix);
    lab->setScaledContents(true);
    lab->setFixedWidth(75);

    // Book's name
    QLabel* name=new QLabel;
    name->setText(book->getName());
    name->setMinimumHeight(35);
    name->setStyleSheet("QLabel {font-size: 15pt;font-family: Freestyle Script}");
      name->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

      //Book's ID
      QLabel* id=new QLabel;
      id->setText(book->getID());
        id->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

      // Book's author
    QLabel* author=new QLabel;
    author->setText(book->getAuthor());
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
    amount->setText("Amount: "+ QString::number(book->getNumOfRemaingBooks()));
    amount->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    QLabel* tag=new QLabel;
    tag->setText("#Tag: "+ book->getTag());
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
   connect(delete_btn,&QPushButton::clicked,this,[book,this]{on_add_to_cart_btn_clicked(book);});
    QPixmap icon_img(":/OrangeIcons/Resource/Orange/plus-square.svg");
       delete_btn->setIcon(icon_img);
      delete_btn->setText("Delete");
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
    borrow_frame->setLayout(new QHBoxLayout);
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
   delete ui->frame->layout();
    ui->frame->setLayout(new QVBoxLayout);


    ProxyLibraryDatabase* proxy=new ProxyLibraryDatabase ;
    // Head
    QFrame* head=new QFrame;
        QGridLayout *layout=new QGridLayout;
        //Add book to library button
        QPushButton* add=new QPushButton;
         QPixmap add_img(":/OrangeIcons/Resource/Orange/file-plus.svg");
         add->setIcon(add_img);
         add->setText("Add book");
         // Delete book to library button
         QPushButton* del=new QPushButton;
         QPixmap del_img(":/OrangeIcons/Resource/Orange/delete.svg");
         del->setIcon(del_img);
         del->setText("Delete book");
         // Check borrowed and damaged book
         QPushButton* check=new QPushButton;
         QPixmap check_img(":/OrangeIcons/Resource/Orange/check-square.svg");
         check->setIcon(check_img);
         check->setText("Check borrowed/damaged book");
         layout->addWidget(add,0,0);
         layout->addWidget(del,0,1);
         layout->addWidget(check,0,2);
         head->setLayout(layout);
         head->setStyleSheet("QPushButton{font: 15pt bold;border-radius: 10px;border: 2px solid red;background-color:#F5F5F5 }");

    ui->frame->layout()->addWidget(head);
  for (auto book:proxy->getListBook())
  {
      QFrame *a=createViewListFrame(&book);
      ui->frame->layout()->addWidget(a);
      ui->frame->layout()->setAlignment(a,Qt::AlignTop);
  }
    ui->frame->layout()->setAlignment(Qt::AlignCenter);


    ui->MainFrame->setCurrentWidget(ui->ViewListBookPage);
}


void MainWindow::on_home_btn_clicked()
{
    ui->MainFrame->setCurrentWidget(ui->MainFramePage1);
}

// ON YOUR BOOK BUTTON
void MainWindow::on_your_book_btn_clicked()
{
   if(login_user){
       qDebug()<<"sdjf";
       delete ui->frame_17->layout();
       ui->frame_17->setLayout(new QVBoxLayout);

       QVector<Book*> BorrowedList=login_user->getBorrowedBook();
       QVector<QDateTime> StartedTime=login_user->getStartedTime();

       int size=BorrowedList.size();
       qDebug()<<size;
       for (int i=0;i<size;i++){
           qDebug()<<"Adding widget: "<<BorrowedList[i]->getName();
           QFrame* a=createYourBookFrame(BorrowedList[i],StartedTime[i].toString(),login_user->getTimeRemainingBook(*BorrowedList[i]));
           ui->frame_17->layout()->addWidget(a);
           ui->frame_17->layout()->setAlignment(a,Qt::AlignTop);
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
        delete ui->frame_18->layout();
        ui->frame_18->setLayout(new QVBoxLayout);
        QVector<Book*> CartList=login_user->getInCartBook();
        int size=CartList.size();
        for (int i=0;i<size;i++){
            QFrame* a=createCartFrame(CartList[i]);
            ui->frame_18->layout()->addWidget(a);
            ui->frame_18->layout()->setAlignment(a,Qt::AlignTop);
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
    delete ui->frame_211->layout();
     ui->frame_211->setLayout(new QVBoxLayout);
    QString line=ui->lineEdit_3->text();
    ProxyLibraryDatabase* proxy=new ProxyLibraryDatabase;
    QVector<Book*> searchByNameRes=proxy->findBookByName(line);
    QVector<Book*> searchByIdRes=proxy->findBookByID(line);
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
}

// ON LOG OUT BUTTON
void MainWindow::on_log_out_btn_clicked()
{
    if(QMessageBox::Yes==QMessageBox::question(this,"Log out","Do you want to log out ?")){
        if(login_user){
            delete login_user;
            login_user=nullptr;
        }
        else if(login_admin){
            delete login_admin;
            login_admin=nullptr;
        }
        hide();
        LoginPage_2* login_ui=new LoginPage_2(this);
        login_ui->show();
    }
}

// ON EXTEND TIME
void MainWindow::on_extend_btn_clicked(Book* book)
{
     if(QMessageBox::Yes==QMessageBox::question(this,"Extend time","Do you want to extend borrowed time ?")){
         login_user->extendBorrowedTime(*book);
     }
}

// ON BORROW BOOK BUTTON
void MainWindow::on_borrow_btn_clicked(Book* book){

    if(QMessageBox::Yes==QMessageBox::question(this,"Borrow book","Do you want to return this book?")){
        if(login_user->borrowBook(book))
        { QMessageBox::information(this,"Borrow Book","This book has been borrowed successfully!");
            qDebug()<<login_user->getBorrowedBook().size();
        }
        else{
            QMessageBox::information(this,"Something's wrong","You Can't this book!");
        }
    }

}
// ON RETURN BUTTON
void MainWindow::on_add_to_cart_btn_clicked(Book* book){

   login_user->addToCart(book);
     QMessageBox::information(this,"Cart","This book has been added to your cart successfully!");
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

//ON RETURN BUTTON BOOK
void MainWindow::on_return_btn_clicked(Book* book){
     if(QMessageBox::Yes==QMessageBox::question(this,"Return book","Do you want to return this book?"))
     {
     clearLayout(ui->frame_17->layout());
     qDeleteAll(ui->frame_17->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
            login_user->returnBook(book);
            MainWindow::on_your_book_btn_clicked();
     }
}

// ON EDIT PROFILE BUTTON
void MainWindow::on_edit_profile_btn_clicked()
{
    ui->name_edit->setText(login_user->showName());
    ui->id->setText((login_user->showID()));
    ui->address_edit->setText(login_user->showAddress());
   if(login_user->showGender()=="Male")
    ui->male_rad_btn->setChecked(true);
   else ui->female_rad_btn->setChecked(true);
   ui->username_edit->setText(login_user->showUsername());
   ui->pass_edit->setText(login_user->showPass());
    ui->MainFrame->setCurrentWidget(ui->editProfile);
}

// ON SAVE BUTTON
void MainWindow::on_save_btn_clicked()
{
    if(QMessageBox::Yes==QMessageBox::question(this,"Save information","Do you want to save information ?")){
         login_user->editName(ui->name_edit->text());
         login_user->editAddress(ui->address_edit->text());
         login_user->editGender(ui->male_rad_btn->isChecked());
         MainWindow::on_edit_profile_btn_clicked();
    }

}


void MainWindow::on_user_btn_clicked()
{
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


void MainWindow::on_ViewMoreBtn_clicked()
{
    MainWindow::on_view_btn_clicked();
}

