QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account.cpp \
    Admin.cpp \
    Book.cpp \
    BookState.cpp \
    HumanDatabase.cpp \
    LibraryDatabase.cpp \
    Person.cpp \
    ProxyLibraryDataBase.cpp \
    RealLibraryDatabase.cpp \
    User.cpp \
    VipUser.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Account.h \
    Admin.h \
    Book.h \
    BookState.h \
    HumanDatabase.h \
    LibraryDatabase.h \
    Person.h \
    ProxyLibraryDataBase.h \
    QuickSort.h \
    RealLibraryDatabase.h \
    SearchHelper.h \
    User.h \
    VipUser.h \
    loginpage.h \
    mainwindow.h

FORMS += \
    loginpage.ui \
    loginpage.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

RC_ICONS = icon.ico
