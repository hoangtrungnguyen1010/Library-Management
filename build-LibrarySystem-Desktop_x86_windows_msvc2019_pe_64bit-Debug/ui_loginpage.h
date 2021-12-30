/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage_2
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QStackedWidget *stackedWidget_2;
    QWidget *stackedWidget_2Page1;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QWidget *page;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_2;
    QLabel *label_7;
    QLabel *label_10;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_27;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLineEdit *fullName;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_15;
    QLineEdit *gender;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_17;
    QLineEdit *id;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_14;
    QLineEdit *address;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_13;
    QLineEdit *username;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    QLineEdit *newpassword;
    QFrame *frame_12;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QLineEdit *retypepassword;
    QWidget *widget_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_8;
    QLabel *label_9;
    QLabel *label_18;
    QWidget *widget_12;
    QLabel *label_25;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_26;
    QLabel *label_24;
    QLabel *label_30;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_14;
    QFrame *frame_14;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_19;
    QLineEdit *fullName_2;
    QFrame *frame_15;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_20;
    QLineEdit *gender_2;
    QFrame *frame_18;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_23;
    QLineEdit *username_2;
    QFrame *frame_16;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_21;
    QLineEdit *id_2;
    QFrame *frame_17;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_22;
    QLineEdit *address_2;
    QWidget *widget_11;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginPage_2)
    {
        if (LoginPage_2->objectName().isEmpty())
            LoginPage_2->setObjectName(QString::fromUtf8("LoginPage_2"));
        LoginPage_2->resize(866, 671);
        LoginPage_2->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(LoginPage_2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: #FFA54F;\n"
""));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(350, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/Resource/Images/login.jpg")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        stackedWidget_2 = new QStackedWidget(centralwidget);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setStyleSheet(QString::fromUtf8(""));
        stackedWidget_2Page1 = new QWidget();
        stackedWidget_2Page1->setObjectName(QString::fromUtf8("stackedWidget_2Page1"));
        verticalLayout = new QVBoxLayout(stackedWidget_2Page1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(stackedWidget_2Page1);
        frame->setObjectName(QString::fromUtf8("frame"));
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: black"));

        verticalLayout_2->addWidget(label_2, 0, Qt::AlignHCenter);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(50, 50));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Images/Resource/Images/user_login.png")));
        label_3->setScaledContents(true);

        verticalLayout_2->addWidget(label_3, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(frame, 0, Qt::AlignHCenter);

        widget_3 = new QWidget(stackedWidget_2Page1);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: #9B0000"));

        horizontalLayout_2->addWidget(label_4, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(stackedWidget_2Page1);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_3 = new QFrame(widget_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(250, 0));
        frame_3->setMaximumSize(QSize(500, 200));
        frame_3->setStyleSheet(QString::fromUtf8("#frame_3{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(30, 30));
        label_8->setMaximumSize(QSize(30, 30));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/user.svg")));
        label_8->setScaledContents(true);

        horizontalLayout_3->addWidget(label_8);

        lineEdit = new QLineEdit(frame_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setPointSize(10);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout_3->addWidget(frame_3);

        frame_2 = new QFrame(widget_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("#frame_2{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(30, 30));
        label_5->setMaximumSize(QSize(30, 30));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/key.svg")));
        label_5->setScaledContents(true);

        horizontalLayout_4->addWidget(label_5);

        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font2);
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEdit_2);


        verticalLayout_3->addWidget(frame_2);


        verticalLayout->addWidget(widget_4, 0, Qt::AlignHCenter);

        frame_5 = new QFrame(stackedWidget_2Page1);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        verticalLayout_4 = new QVBoxLayout(frame_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton = new QPushButton(frame_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(150, 0));
        pushButton->setMaximumSize(QSize(200, 50));
        QFont font3;
        font3.setPointSize(15);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: white;\n"
"background-color: #9B0000;\n"
"border-radius: 10px;\n"
"border: 2px solid  #9B0000;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: #CD1818;\n"
"cursor: pointer;\n"
"}"));

        verticalLayout_4->addWidget(pushButton);


        verticalLayout->addWidget(frame_5, 0, Qt::AlignHCenter);

        widget_6 = new QWidget(stackedWidget_2Page1);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_4 = new QFrame(widget_6);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_2 = new QPushButton(frame_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("color:  #9B0000"));

        horizontalLayout_5->addWidget(pushButton_2);

        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: white"));

        horizontalLayout_5->addWidget(label_6);

        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("color:  #9B0000"));

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout_5->addWidget(frame_4, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(widget_6);

        stackedWidget_2->addWidget(stackedWidget_2Page1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_7 = new QVBoxLayout(page);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget_2 = new QWidget(page);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 10, 271, 41));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: black"));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(130, 50, 101, 31));
        QFont font4;
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        label_10->setFont(font4);
        label_10->setStyleSheet(QString::fromUtf8("color: #9B0000"));

        verticalLayout_7->addWidget(widget_2);

        widget_7 = new QWidget(page);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_6 = new QVBoxLayout(widget_7);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_27 = new QLabel(widget_7);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        QFont font5;
        font5.setPointSize(11);
        font5.setItalic(true);
        label_27->setFont(font5);
        label_27->setStyleSheet(QString::fromUtf8("color: black"));

        verticalLayout_6->addWidget(label_27);

        widget = new QWidget(widget_7);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        frame_7 = new QFrame(widget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setMinimumSize(QSize(220, 0));
        frame_7->setMaximumSize(QSize(500, 200));
        frame_7->setStyleSheet(QString::fromUtf8("#frame_7{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_11 = new QLabel(frame_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(30, 30));
        label_11->setMaximumSize(QSize(30, 30));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/user.svg")));
        label_11->setScaledContents(true);

        horizontalLayout_7->addWidget(label_11);

        fullName = new QLineEdit(frame_7);
        fullName->setObjectName(QString::fromUtf8("fullName"));
        fullName->setMinimumSize(QSize(0, 30));
        fullName->setFont(font2);
        fullName->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));

        horizontalLayout_7->addWidget(fullName);


        horizontalLayout_6->addWidget(frame_7);

        frame_11 = new QFrame(widget);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setMinimumSize(QSize(110, 0));
        frame_11->setStyleSheet(QString::fromUtf8("#frame_11{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_11 = new QHBoxLayout(frame_11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_15 = new QLabel(frame_11);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(30, 30));
        label_15->setMaximumSize(QSize(30, 30));
        label_15->setStyleSheet(QString::fromUtf8(""));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/users.svg")));
        label_15->setScaledContents(true);

        horizontalLayout_11->addWidget(label_15);

        gender = new QLineEdit(frame_11);
        gender->setObjectName(QString::fromUtf8("gender"));
        gender->setFont(font2);
        gender->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));
        gender->setEchoMode(QLineEdit::Normal);

        horizontalLayout_11->addWidget(gender);


        horizontalLayout_6->addWidget(frame_11);


        verticalLayout_6->addWidget(widget);

        frame_13 = new QFrame(widget_7);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setMinimumSize(QSize(250, 0));
        frame_13->setMaximumSize(QSize(2000, 200));
        frame_13->setStyleSheet(QString::fromUtf8("#frame_13{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame_13);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_17 = new QLabel(frame_13);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(30, 30));
        label_17->setMaximumSize(QSize(30, 30));
        label_17->setStyleSheet(QString::fromUtf8(""));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/hash.svg")));
        label_17->setScaledContents(true);

        horizontalLayout_13->addWidget(label_17);

        id = new QLineEdit(frame_13);
        id->setObjectName(QString::fromUtf8("id"));
        id->setMinimumSize(QSize(0, 30));
        id->setFont(font2);
        id->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));

        horizontalLayout_13->addWidget(id);


        verticalLayout_6->addWidget(frame_13);

        frame_10 = new QFrame(widget_7);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setMinimumSize(QSize(250, 0));
        frame_10->setMaximumSize(QSize(2000, 200));
        frame_10->setStyleSheet(QString::fromUtf8("#frame_10{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_10);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_14 = new QLabel(frame_10);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(30, 30));
        label_14->setMaximumSize(QSize(30, 30));
        label_14->setStyleSheet(QString::fromUtf8(""));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/home.svg")));
        label_14->setScaledContents(true);

        horizontalLayout_10->addWidget(label_14);

        address = new QLineEdit(frame_10);
        address->setObjectName(QString::fromUtf8("address"));
        address->setMinimumSize(QSize(0, 30));
        address->setFont(font2);
        address->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));

        horizontalLayout_10->addWidget(address);


        verticalLayout_6->addWidget(frame_10);

        frame_9 = new QFrame(widget_7);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setMinimumSize(QSize(250, 0));
        frame_9->setMaximumSize(QSize(2000, 200));
        frame_9->setStyleSheet(QString::fromUtf8("#frame_9{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_13 = new QLabel(frame_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(30, 30));
        label_13->setMaximumSize(QSize(30, 30));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/user.svg")));
        label_13->setScaledContents(true);

        horizontalLayout_9->addWidget(label_13);

        username = new QLineEdit(frame_9);
        username->setObjectName(QString::fromUtf8("username"));
        username->setMinimumSize(QSize(0, 30));
        username->setFont(font2);
        username->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));

        horizontalLayout_9->addWidget(username);


        verticalLayout_6->addWidget(frame_9);

        frame_8 = new QFrame(widget_7);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setStyleSheet(QString::fromUtf8("#frame_8{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_12 = new QLabel(frame_8);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(30, 30));
        label_12->setMaximumSize(QSize(30, 30));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/key.svg")));
        label_12->setScaledContents(true);

        horizontalLayout_8->addWidget(label_12);

        newpassword = new QLineEdit(frame_8);
        newpassword->setObjectName(QString::fromUtf8("newpassword"));
        newpassword->setFont(font2);
        newpassword->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));
        newpassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_8->addWidget(newpassword);


        verticalLayout_6->addWidget(frame_8);

        frame_12 = new QFrame(widget_7);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setStyleSheet(QString::fromUtf8("#frame_12{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_12);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_16 = new QLabel(frame_12);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(30, 30));
        label_16->setMaximumSize(QSize(30, 30));
        label_16->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/key.svg")));
        label_16->setScaledContents(true);

        horizontalLayout_12->addWidget(label_16);

        retypepassword = new QLineEdit(frame_12);
        retypepassword->setObjectName(QString::fromUtf8("retypepassword"));
        retypepassword->setFont(font2);
        retypepassword->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));
        retypepassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_12->addWidget(retypepassword);


        verticalLayout_6->addWidget(frame_12);


        verticalLayout_7->addWidget(widget_7);

        widget_5 = new QWidget(page);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        pushButton_4 = new QPushButton(widget_5);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 10, 150, 31));
        pushButton_4->setMinimumSize(QSize(150, 0));
        pushButton_4->setMaximumSize(QSize(200, 50));
        QFont font6;
        font6.setPointSize(15);
        font6.setBold(false);
        font6.setWeight(50);
        pushButton_4->setFont(font6);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:  #F9DFDC;\n"
"background-color: #9B0000;\n"
"border-radius: 10px;\n"
"border: 2px solid  #9B0000;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: #CD1818;\n"
"cursor: pointer;\n"
"}"));
        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(200, 10, 150, 31));
        pushButton_5->setMinimumSize(QSize(150, 0));
        pushButton_5->setMaximumSize(QSize(200, 50));
        pushButton_5->setFont(font6);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: black;\n"
"background-color: #C9CCD5;\n"
"border-radius: 10px;\n"
"border: 2px solid  #C9CCD5;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: #DDDDDD;\n"
"cursor: pointer;\n"
"}"));

        verticalLayout_7->addWidget(widget_5);

        stackedWidget_2->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_9 = new QVBoxLayout(page_2);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        widget_8 = new QWidget(page_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        label_9 = new QLabel(widget_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 0, 271, 51));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: black"));
        label_18 = new QLabel(widget_8);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(90, 50, 191, 41));
        label_18->setFont(font4);
        label_18->setStyleSheet(QString::fromUtf8("color: #9B0000"));

        verticalLayout_9->addWidget(widget_8);

        widget_12 = new QWidget(page_2);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        label_25 = new QLabel(widget_12);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 50, 351, 21));
        label_25->setFont(font5);
        label_25->setStyleSheet(QString::fromUtf8("color: black"));
        widget_13 = new QWidget(widget_12);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setGeometry(QRect(0, 0, 139, 42));
        horizontalLayout_20 = new QHBoxLayout(widget_13);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_26 = new QLabel(widget_13);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/alert-circle.svg")));

        horizontalLayout_20->addWidget(label_26);

        label_24 = new QLabel(widget_13);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        QFont font7;
        font7.setPointSize(13);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        label_24->setFont(font7);
        label_24->setStyleSheet(QString::fromUtf8("color: blue;"));

        horizontalLayout_20->addWidget(label_24);

        label_30 = new QLabel(widget_12);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 80, 351, 21));
        label_30->setFont(font5);
        label_30->setStyleSheet(QString::fromUtf8("color: black"));

        verticalLayout_9->addWidget(widget_12);

        widget_9 = new QWidget(page_2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        verticalLayout_8 = new QVBoxLayout(widget_9);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget_10 = new QWidget(widget_9);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_14 = new QHBoxLayout(widget_10);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        frame_14 = new QFrame(widget_10);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setMinimumSize(QSize(220, 0));
        frame_14->setMaximumSize(QSize(500, 200));
        frame_14->setStyleSheet(QString::fromUtf8("#frame_14{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        horizontalLayout_15 = new QHBoxLayout(frame_14);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_19 = new QLabel(frame_14);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(30, 30));
        label_19->setMaximumSize(QSize(30, 30));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/user.svg")));
        label_19->setScaledContents(true);

        horizontalLayout_15->addWidget(label_19);

        fullName_2 = new QLineEdit(frame_14);
        fullName_2->setObjectName(QString::fromUtf8("fullName_2"));
        fullName_2->setMinimumSize(QSize(0, 30));
        fullName_2->setFont(font2);
        fullName_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));

        horizontalLayout_15->addWidget(fullName_2);


        horizontalLayout_14->addWidget(frame_14);

        frame_15 = new QFrame(widget_10);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setMinimumSize(QSize(110, 0));
        frame_15->setStyleSheet(QString::fromUtf8("#frame_15{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(frame_15);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_20 = new QLabel(frame_15);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(30, 30));
        label_20->setMaximumSize(QSize(30, 30));
        label_20->setStyleSheet(QString::fromUtf8(""));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/users.svg")));
        label_20->setScaledContents(true);

        horizontalLayout_16->addWidget(label_20);

        gender_2 = new QLineEdit(frame_15);
        gender_2->setObjectName(QString::fromUtf8("gender_2"));
        gender_2->setFont(font2);
        gender_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));
        gender_2->setEchoMode(QLineEdit::Normal);

        horizontalLayout_16->addWidget(gender_2);


        horizontalLayout_14->addWidget(frame_15);


        verticalLayout_8->addWidget(widget_10);

        frame_18 = new QFrame(widget_9);
        frame_18->setObjectName(QString::fromUtf8("frame_18"));
        frame_18->setMinimumSize(QSize(250, 0));
        frame_18->setMaximumSize(QSize(2000, 200));
        frame_18->setStyleSheet(QString::fromUtf8("#frame_18{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        horizontalLayout_19 = new QHBoxLayout(frame_18);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_23 = new QLabel(frame_18);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMinimumSize(QSize(30, 30));
        label_23->setMaximumSize(QSize(30, 30));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/user.svg")));
        label_23->setScaledContents(true);

        horizontalLayout_19->addWidget(label_23);

        username_2 = new QLineEdit(frame_18);
        username_2->setObjectName(QString::fromUtf8("username_2"));
        username_2->setMinimumSize(QSize(0, 30));
        username_2->setFont(font2);
        username_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));

        horizontalLayout_19->addWidget(username_2);


        verticalLayout_8->addWidget(frame_18);

        frame_16 = new QFrame(widget_9);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setMinimumSize(QSize(250, 0));
        frame_16->setMaximumSize(QSize(2000, 200));
        frame_16->setStyleSheet(QString::fromUtf8("#frame_16{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        horizontalLayout_17 = new QHBoxLayout(frame_16);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_21 = new QLabel(frame_16);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(30, 30));
        label_21->setMaximumSize(QSize(30, 30));
        label_21->setStyleSheet(QString::fromUtf8(""));
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/hash.svg")));
        label_21->setScaledContents(true);

        horizontalLayout_17->addWidget(label_21);

        id_2 = new QLineEdit(frame_16);
        id_2->setObjectName(QString::fromUtf8("id_2"));
        id_2->setMinimumSize(QSize(0, 30));
        id_2->setFont(font2);
        id_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));

        horizontalLayout_17->addWidget(id_2);


        verticalLayout_8->addWidget(frame_16);

        frame_17 = new QFrame(widget_9);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        frame_17->setMinimumSize(QSize(250, 0));
        frame_17->setMaximumSize(QSize(2000, 200));
        frame_17->setStyleSheet(QString::fromUtf8("#frame_17{\n"
"border-radius: 10px;\n"
"border: 2px solid #9B0000;\n"
"}"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        horizontalLayout_18 = new QHBoxLayout(frame_17);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_22 = new QLabel(frame_17);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(30, 30));
        label_22->setMaximumSize(QSize(30, 30));
        label_22->setStyleSheet(QString::fromUtf8(""));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/WhiteIcons/Resource/White/home.svg")));
        label_22->setScaledContents(true);

        horizontalLayout_18->addWidget(label_22);

        address_2 = new QLineEdit(frame_17);
        address_2->setObjectName(QString::fromUtf8("address_2"));
        address_2->setMinimumSize(QSize(0, 30));
        address_2->setFont(font2);
        address_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color: transparent;\n"
"border: none"));

        horizontalLayout_18->addWidget(address_2);


        verticalLayout_8->addWidget(frame_17);


        verticalLayout_9->addWidget(widget_9);

        widget_11 = new QWidget(page_2);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        pushButton_6 = new QPushButton(widget_11);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 30, 150, 31));
        pushButton_6->setMinimumSize(QSize(150, 0));
        pushButton_6->setMaximumSize(QSize(200, 50));
        pushButton_6->setFont(font6);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:  #F9DFDC;\n"
"background-color: #9B0000;\n"
"border-radius: 10px;\n"
"border: 2px solid  #9B0000;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: #CD1818;\n"
"cursor: pointer;\n"
"}"));
        pushButton_7 = new QPushButton(widget_11);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(200, 30, 150, 31));
        pushButton_7->setMinimumSize(QSize(150, 0));
        pushButton_7->setMaximumSize(QSize(200, 50));
        pushButton_7->setFont(font6);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: black;\n"
"background-color: #C9CCD5;\n"
"border-radius: 10px;\n"
"border: 2px solid  #C9CCD5;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: #DDDDDD;\n"
"cursor: pointer;\n"
"}"));

        verticalLayout_9->addWidget(widget_11);

        stackedWidget_2->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget_2);

        LoginPage_2->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginPage_2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginPage_2->setStatusBar(statusbar);

        retranslateUi(LoginPage_2);

        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginPage_2);
    } // setupUi

    void retranslateUi(QMainWindow *LoginPage_2)
    {
        LoginPage_2->setWindowTitle(QApplication::translate("LoginPage_2", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("LoginPage_2", "Library Management", nullptr));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("LoginPage_2", "Login to your account", nullptr));
        label_8->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("LoginPage_2", "User Name", nullptr));
        label_5->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("LoginPage_2", "Password", nullptr));
        pushButton->setText(QApplication::translate("LoginPage_2", "L o g i n", nullptr));
        pushButton_2->setText(QApplication::translate("LoginPage_2", "Create an new account ?", nullptr));
        label_6->setText(QApplication::translate("LoginPage_2", "or", nullptr));
        pushButton_3->setText(QApplication::translate("LoginPage_2", "Forget your passoword?", nullptr));
        label_7->setText(QApplication::translate("LoginPage_2", "Library Management", nullptr));
        label_10->setText(QApplication::translate("LoginPage_2", "Register", nullptr));
        label_27->setText(QApplication::translate("LoginPage_2", "Enter \"0\" in Gender if you are Male, enter \"1\" otherwise.", nullptr));
        label_11->setText(QString());
        fullName->setPlaceholderText(QApplication::translate("LoginPage_2", "Full Name", nullptr));
        label_15->setText(QString());
        gender->setPlaceholderText(QApplication::translate("LoginPage_2", "Gender", nullptr));
        label_17->setText(QString());
        id->setPlaceholderText(QApplication::translate("LoginPage_2", "ID", nullptr));
        label_14->setText(QString());
        address->setPlaceholderText(QApplication::translate("LoginPage_2", "Address", nullptr));
        label_13->setText(QString());
        username->setPlaceholderText(QApplication::translate("LoginPage_2", "User Name", nullptr));
        label_12->setText(QString());
        newpassword->setPlaceholderText(QApplication::translate("LoginPage_2", "New Password", nullptr));
        label_16->setText(QString());
        retypepassword->setPlaceholderText(QApplication::translate("LoginPage_2", "Retype Password", nullptr));
        pushButton_4->setText(QApplication::translate("LoginPage_2", "S u b m i t", nullptr));
        pushButton_5->setText(QApplication::translate("LoginPage_2", "C a n c e l", nullptr));
        label_9->setText(QApplication::translate("LoginPage_2", "Library Management", nullptr));
        label_18->setText(QApplication::translate("LoginPage_2", "Forgot password", nullptr));
        label_25->setText(QApplication::translate("LoginPage_2", "Fill in correctly your information to get your password.", nullptr));
        label_26->setText(QString());
        label_24->setText(QApplication::translate("LoginPage_2", "Instruction:", nullptr));
        label_30->setText(QApplication::translate("LoginPage_2", "Enter \"0\" in Gender if you are Male, enter \"1\" otherwise.", nullptr));
        label_19->setText(QString());
        fullName_2->setPlaceholderText(QApplication::translate("LoginPage_2", "Enter your name", nullptr));
        label_20->setText(QString());
        gender_2->setPlaceholderText(QApplication::translate("LoginPage_2", "Gender?", nullptr));
        label_23->setText(QString());
        username_2->setPlaceholderText(QApplication::translate("LoginPage_2", "Enter your username", nullptr));
        label_21->setText(QString());
        id_2->setPlaceholderText(QApplication::translate("LoginPage_2", "Enter your ID", nullptr));
        label_22->setText(QString());
        address_2->setPlaceholderText(QApplication::translate("LoginPage_2", "Enter your address", nullptr));
        pushButton_6->setText(QApplication::translate("LoginPage_2", "S u b m i t", nullptr));
        pushButton_7->setText(QApplication::translate("LoginPage_2", "C a n c e l", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage_2: public Ui_LoginPage_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
