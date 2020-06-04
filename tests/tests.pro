include(gtest_dependency.pri)

LIBS += -L$$PWD/../external/SFML-2.5.1/lib

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += $$PWD/../external/SFML-2.5.1/include
DEPENDPATH += $$PWD/../external/SFML-2.5.1/include

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += SPRITE=\\\"$$PWD/../app/sprites\\\" \

HEADERS +=      \ \
    archer_test.h \
    location_test.h \
    update_test.h

SOURCES +=  main.cpp

INCLUDEPATH += ../app
