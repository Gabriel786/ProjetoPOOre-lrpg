TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    personagem.cpp \
    gostos.cpp \
    id.cpp \
    Eventos.cpp \
    personagens.cpp \
    menu.cpp \
    Gerador.cpp

HEADERS += \
    personagem.h \
    gostos.h \
    randperson.h \
    id.h \
    nomestxt.h \
    Eventos.h \
    personagens.h \
    menu.h \
    Gerador.h

STATECHARTS +=
