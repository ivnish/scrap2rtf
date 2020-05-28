TEMPLATE = app
CONFIG += console
CONFIG -= qt
TARGET = scrap2rtf

SOURCES += \
    src/main.cpp \
    src/helpers.cpp

HEADERS += \
    src/main.h \
    src/head.h \
    src/helpers.h

OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = src
