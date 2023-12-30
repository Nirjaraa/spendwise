QT       += core gui sql
QT       += core gui charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutus.cpp \
    budget.cpp \
    changepw.cpp \
    checkbalance.cpp \
    dashboard.cpp \
    editprofile.cpp \
    expenses.cpp \
    linkin.cpp \
    logout.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow1.cpp \
    manual.cpp \
    newincome.cpp \
    records.cpp \
    savings.cpp \
    signin.cpp

HEADERS += \
    aboutus.h \
    budget.h \
    changepw.h \
    checkbalance.h \
    dashboard.h \
    editprofile.h \
    expenses.h \
    linkin.h \
    logout.h \
    mainwindow.h \
    mainwindow1.h \
    manual.h \
    newincome.h \
    records.h \
    savings.h \
    signin.h \
    userdata.h

FORMS += \
    aboutus.ui \
    budget.ui \
    changepw.ui \
    checkbalance.ui \
    dashboard.ui \
    editprofile.ui \
    expenses.ui \
    linkin.ui \
    logout.ui \
    mainwindow.ui \
    mainwindow1.ui \
    manual.ui \
    newincome.ui \
    records.ui \
    savings.ui \
    signin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../../spendwise/resources.qrc \
    resources.qrc
