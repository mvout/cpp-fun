TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    splitter.cpp \
    stores.cpp \
    prints.cpp


HEADERS += \
    splitter.hh \
    stores.hh \
    prints.hh

DISTFILES += \
    suomikaupat.csv
