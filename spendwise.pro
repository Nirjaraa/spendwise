QT       += core gui sql

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
    financial.cpp \
    linkin.cpp \
    logout.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow1.cpp \
    manual.cpp \
    myprofile.cpp \
    newincome.cpp \
    savings.cpp \
    signin.cpp \
    warning.cpp

HEADERS += \
    aboutus.h \
    budget.h \
    changepw.h \
    checkbalance.h \
    dashboard.h \
    editprofile.h \
    expenses.h \
    financial.h \
    linkin.h \
    logout.h \
    mainwindow.h \
    mainwindow1.h \
    manual.h \
    myprofile.h \
    newincome.h \
    savings.h \
    signin.h \
    warning.h

FORMS += \
    aboutus.ui \
    budget.ui \
    changepw.ui \
    checkbalance.ui \
    dashboard.ui \
    editprofile.ui \
    expenses.ui \
    financial.ui \
    linkin.ui \
    logout.ui \
    mainwindow.ui \
    mainwindow1.ui \
    manual.ui \
    myprofile.ui \
    newincome.ui \
    savings.ui \
    signin.ui \
    warning.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../../spendwise/resources.qrc \
    resources/resources.qrc
