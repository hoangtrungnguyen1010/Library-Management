#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, User* user)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->_user = user;
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_add_to_cart_btn_clicked(){
    ui->MainFrame->setCurrentWidget(ui->MainFramePage1);
}
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

// On view button clicked()
void MainWindow::on_view_btn_clicked()
{
   delete ui->frame->layout();
    ui->frame->setLayout(new QVBoxLayout);

    RealLibraryDatabase* lib=new RealLibraryDatabase;
    lib->uploadBook();

    // Head
    QFrame* head=new QFrame;
    if(p.showType()=="Admin"){
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

