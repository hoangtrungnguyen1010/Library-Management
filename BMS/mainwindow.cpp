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

//
void MainWindow::on_add_to_cart_btn_clicked(){
    ui->MainFrame->setCurrentWidget(ui->MainFramePage1);
}
void MainWindow::on_return_btn_clicked(){
    qDebug()<<"1";
}

// Create an vỉew list book freame
QFrame* MainWindow::createViewListFrame(Book book){
    QFrame* res=new QFrame;
    res->setLayout(new QHBoxLayout);
    res->setFixedHeight(100);
    res->setMinimumWidth(500);
    res->setMaximumWidth(1000);
   res->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    res->setStyleSheet("background-color: #F0ECE3");


    // Book image
    QLabel* lab=new QLabel;
    QString url=":/Images/Resource/Images/"+book.getID();
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
    amount->setText("Amount: "+ QString::number(book.getQuanlity()));
    amount->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    QLabel* tag=new QLabel;
    tag->setText("#Tag: "+ book.getTag());
    tag->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    QFrame* amount_tag=new QFrame;
   amount_tag->setLayout(new QVBoxLayout);
   amount_tag->layout()->addWidget(amount);
   amount_tag->layout()->addWidget(tag);

    // Add to cart button

   add_to_cart_btn=new AddToCartBtn;
   connect(add_to_cart_btn,&AddToCartBtn::clicked,this,&MainWindow::on_add_to_cart_btn_clicked);
    QPixmap icon_img(":/OrangeIcons/Resource/Orange/plus-square.svg");
       add_to_cart_btn->setIcon(icon_img);
      add_to_cart_btn->setText("Borrow");
      add_to_cart_btn->setMaximumWidth(100);
      add_to_cart_btn->setStyleSheet("font: 15pt bold;background-color: #DE834D;border-radius: 10px");
    QFrame* borrow_frame=new QFrame;
    borrow_frame->setLayout(new QHBoxLayout);
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
    QString url=":/Images/Resource/Images/"+book.getID();
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

    // Return and extend button
     QPushButton* return_icon=new QPushButton;
     connect(return_icon,&QPushButton::clicked,this,&MainWindow::on_return_btn_clicked);
     QPixmap return_img(":/OrangeIcons/Resource/Orange/corner-up-left.svg");
     return_icon->setIcon(return_img);
     return_icon->setText("Return Book");

     QPushButton* extend_icon=new QPushButton;
     connect(extend_icon,&QPushButton::clicked,this,&MainWindow::on_return_btn_clicked);
      QPixmap extend_img(":/OrangeIcons/Resource/Orange/corner-up-left.svg");
      extend_icon->setIcon(extend_img);
      extend_icon->setText("Extend time");

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

// On view button clicked()
void MainWindow::on_view_btn_clicked()
{
   delete ui->frame->layout();
    ui->frame->setLayout(new QVBoxLayout);

    RealLibraryDatabase* lib=RealLibraryDatabase::getInstance();
    // Head
    QFrame* head=new QFrame;
    if(login_user->showType()=="Admin"){
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
    }
    ui->frame->layout()->addWidget(head);
    //Book data
  for (auto book:lib->getListBook())
  {
      QFrame *a=createViewListFrame(book);
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

void MainWindow::on_extend_btn_clicked()
{
     ui->MainFrame->setCurrentWidget(ui->MainFramePage1);
}


void MainWindow::on_your_book_btn_clicked()
{
    delete ui->frame_17->layout();
    ui->frame_17->setLayout(new QVBoxLayout);
    QVector<Book> BorrowedList=login_user->getBorrowedBook();
    QVector<QDateTime> StartedTime=login_user->getStartedTime();
    qDebug()<<StartedTime[0].toString();
    int size=BorrowedList.size();
    for (int i=0;i<size;i++){
        QFrame* a=createYourBookFrame(BorrowedList[i],StartedTime[i].toString(),login_user->getTimeRemainingBook(BorrowedList[i]));
        ui->frame_17->layout()->addWidget(a);
        ui->frame_17->layout()->setAlignment(a,Qt::AlignTop);
    }
    ui->frame_17->layout()->setAlignment(Qt::AlignTop);

    ui->MainFrame->setCurrentWidget(ui->YourBook);
}

