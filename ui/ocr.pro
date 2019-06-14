#-------------------------------------------------
#
# Project created by QtCreator 2019-02-19T22:44:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ocr
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    OcrWorker.cpp

HEADERS  += widget.h \
    OcrWorker.h

FORMS    += widget.ui

DESTDIR = ../bin
