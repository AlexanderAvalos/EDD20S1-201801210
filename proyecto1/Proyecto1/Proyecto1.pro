QT += core
QT -= gui

CONFIG += c++11

TARGET = Proyecto1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    juego.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    nodo_lista_circular.h \
    cola.h \
    nodo_listadoble.h \
    nodo_arbol_busqueda.h \
    datos_listasimple_t.h \
    datos_matrizdispersa.h \
    nodo_listasimple_t.h \
    nodo_listasimple_jp.h \
    nodo_matrizdispersa.h \
    arbol_buscar.h \
    listadoble.h \
    nodocola.h \
    listacirulardoble.h \
    nodolista.h \
    listaletras.h \
    listasimplejp.h \
    listatop.h \
    matrizdispersa.h \
    juego.h
