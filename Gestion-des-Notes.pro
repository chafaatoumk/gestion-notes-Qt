QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    uiadministrateur.cpp \
    uiauthentication.cpp \
    user.cpp \
    service.cpp \
    flowcontroller.cpp \
    dbaccess.cpp \
    usermodel.cpp


HEADERS += \
    uiadministrateur.h \
    uiauthentication.h \
    user.h \
    service.h \
    flowcontroller.h \
    dbaccess.h \
    usermodel.h

FORMS += \
    uiadministrateur.ui \
    uiauthentication.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
