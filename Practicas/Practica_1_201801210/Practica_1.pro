QT += core
QT -= gui

CONFIG += c++11

TARGET = Practica_1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    lista_doble.cpp \
    lista_circular.cpp \
    pilaB.cpp \
    editor.cpp \
    abrir_en_editor.cpp

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
    lista_doble.h \
    lista_circular.h \
    pilaB.h \
    editor.h \
    abrir_en_editor.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ncurses-6.1/lib/release/ -lncurses
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ncurses-6.1/lib/debug/ -lncurses
else:unix: LIBS += -L$$PWD/../ncurses-6.1/lib/ -lncurses

INCLUDEPATH += $$PWD/../ncurses-6.1/include
DEPENDPATH += $$PWD/../ncurses-6.1/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/release/libncurses.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/debug/libncurses.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/release/ncurses.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/debug/ncurses.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/libncurses.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ncurses-6.1/lib/release/ -lform
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ncurses-6.1/lib/debug/ -lform
else:unix: LIBS += -L$$PWD/../ncurses-6.1/lib/ -lform

INCLUDEPATH += $$PWD/../ncurses-6.1/include
DEPENDPATH += $$PWD/../ncurses-6.1/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/release/libform.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/debug/libform.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/release/form.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/debug/form.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/libform.a

unix|win32: LIBS += -lncurses_g

unix|win32: LIBS += -lform_g

unix|win32: LIBS += -lncurses++_g

unix|win32: LIBS += -lmenu

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ncurses-6.1/lib/release/ -lmenu_g
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ncurses-6.1/lib/debug/ -lmenu_g
else:unix: LIBS += -L$$PWD/../ncurses-6.1/lib/ -lmenu_g

INCLUDEPATH += $$PWD/../ncurses-6.1/include
DEPENDPATH += $$PWD/../ncurses-6.1/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/release/libmenu_g.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/debug/libmenu_g.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/release/menu_g.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/debug/menu_g.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ncurses-6.1/lib/libmenu_g.a

unix|win32: LIBS += -lpanel_g


unix|win32: LIBS += -lncurses++
