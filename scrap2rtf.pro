TEMPLATE = app
CONFIG += console
CONFIG -= qt
TARGET = scrap2rtf

SOURCES += \
    src/main.cpp \
    src/helpers.cpp

HEADERS += \
    src/main.h \
    src/helpers.h \
    src/head.h

OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = src

INSTALLS += target languages

target.path = /usr/bin

languages.path = /usr/share/locale/ru/LC_MESSAGES
languages.files += po/scrap2rtf.mo
