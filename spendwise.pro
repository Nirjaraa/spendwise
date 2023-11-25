QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    checkbalance.cpp \
    dashboard.cpp \
    linkin.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow1.cpp \
    myprofile.cpp \
    sign2.cpp \
    signin.cpp \
    signin3.cpp

HEADERS += \
    checkbalance.h \
    dashboard.h \
    linkin.h \
    mainwindow.h \
    mainwindow1.h \
    myprofile.h \
    sign2.h \
    signin.h \
    signin3.h

FORMS += \
    checkbalance.ui \
    dashboard.ui \
    linkin.ui \
    mainwindow.ui \
    mainwindow1.ui \
    myprofile.ui \
    sign2.ui \
    signin.ui \
    signin3.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../../spendwise/resources.qrc
