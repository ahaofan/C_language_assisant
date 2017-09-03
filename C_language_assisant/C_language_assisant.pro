#-------------------------------------------------
#
# Project created by QtCreator 2017-09-02T11:28:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = C_language_assisant
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MyGlobalShortCut/MyGlobalShortCut.cpp \
    MyGlobalShortCut/MyWinEventFilter.cpp

HEADERS  += mainwindow.h \
    MyGlobalShortCut/MyGlobalShortCut.h \
    MyGlobalShortCut/MyWinEventFilter.h

FORMS    += mainwindow.ui

RESOURCES += \
    src.qrc
RC_FILE = proj.rc
