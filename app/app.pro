LIBS += -L$$PWD/../external/SFML-2.5.1/lib

TEMPLATE = app
CONFIG += gui
CONFIG -= app_bundle
CONFIG -= qt

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += $$PWD/../external/SFML-2.5.1/include
DEPENDPATH += $$PWD/../external/SFML-2.5.1/include

SOURCES += \
        main.cpp

DEFINES += SPRITE=\\\"$$PWD/sprites\\\" \



QMAKE_CFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

HEADERS += \
    global_vars.h \
    helper.h
