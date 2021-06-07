QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classe.cpp \
    classmodel.cpp \
    formateur.cpp \
    formateurmodel.cpp \
    gestionetudiant.cpp \
    gestionformateur.cpp \
    main.cpp \
    module.cpp \
    modulemodel.cpp \
    responsable.cpp \
    uiadministrateur.cpp \
    uiauthentication.cpp \
    uiclasse.cpp \
    uimodule.cpp \
    user.cpp \
    service.cpp \
    flowcontroller.cpp \
    dbaccess.cpp \
    usermodel.cpp


HEADERS += \
    classe.h \
    classmodel.h \
    formateur.h \
    formateurmodel.h \
    gestionetudiant.h \
    gestionformateur.h \
    module.h \
    modulemodel.h \
    responsable.h \
    uiadministrateur.h \
    uiauthentication.h \
    uiclasse.h \
    uimodule.h \
    user.h \
    service.h \
    flowcontroller.h \
    dbaccess.h \
    usermodel.h

FORMS += \
    gestionetudiant.ui \
    gestionformateur.ui \
    responsable.ui \
    uiadministrateur.ui \
    uiauthentication.ui \
    uiclasse.ui \
    uimodule.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc
