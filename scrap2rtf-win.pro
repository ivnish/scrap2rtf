TEMPLATE = app
CONFIG += console
CONFIG -= qt
TARGET = scrap2rtf

SOURCES += \
    src/main.cpp \
    src/common_func.cpp

HEADERS += \
    src/main.h \
    src/common_head.h \
    src/common_func.h

OBJECTS_DIR = src
MOC_DIR = src
UI_DIR = src
DESTDIR = src

