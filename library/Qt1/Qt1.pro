#-------------------------------------------------
#
# Project created by QtCreator 2018-03-25T19:57:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt1
TEMPLATE = app


SOURCES += main.cpp\
        library.cpp \
    reader.cpp \
    book.cpp \
    bdatabase.cpp \
    rdatabase.cpp

HEADERS  += library.h \
    reader.h \
    book.h \
    bdatabase.h \
    rdatabase.h

FORMS    += library.ui
CONFIG+=console
DEFINES += _GLIBCXX_USE_CXX11_ABI=0
