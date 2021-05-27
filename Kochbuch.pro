QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EinkaufslisteDialog.cpp \
    NeuDialog.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    EinkaufslisteDialog.h \
    MainWindow.h \
    NeuDialog.h

FORMS += \
    EinkaufslisteDialog.ui \
    MainWindow.ui \
    NeuDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../build-DAOLib-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/ -lDAOLib

INCLUDEPATH += $$PWD/../DAOLib
DEPENDPATH += $$PWD/../DAOLib
