QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    Proxy.cpp \
    RealLibraryDatabase.cpp \
    User.cpp \
    VipUser.cpp \
    main.cpp

HEADERS += \
    Account.h \
    Admin.h \
    Book.h \
    BookState.h \
    HumanDatabase.h \
    LibraryDatabase.h \
    Person.h \
    Proxy.h \
    QuickSort.h \
    RealLibraryDatabase.h \
    User.h \
    VipUser.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
