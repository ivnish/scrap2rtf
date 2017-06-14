TEMPLATE = app
CONFIG += console
CONFIG -= qt
TARGET = src/scrap2rtf

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

INSTALLS += target languages

target.path = /usr/bin

languages.path = /usr/share/locale/ru/LC_MESSAGES
languages.files += po/scrap2rtf.mo

