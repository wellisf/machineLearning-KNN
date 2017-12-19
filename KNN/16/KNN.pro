QT += core
QT -= gui

CONFIG += c++11

TARGET = KNN
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Knn.cpp \
    Parser.cpp

HEADERS += \
    Knn.h \
    Parser.h
