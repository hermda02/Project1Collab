TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L/usr/local/lib
LIBS += -larmadillo -llapack -lblas
INCLUDEPATH += /usr/local/include

SOURCES += main.cpp
