QT += core network gui widgets\
      sql

TARGET = QtSimpleChatServer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += debug_and_release

HEADERS += \
    InMemoryDataBase.h \
    question.h \
    quiz.h \
    server.h \
    serverworker.h \
    serverwindow.h \
    variant.h

SOURCES += \
    InMemoryDataBase.cpp \
    question.cpp \
    quiz.cpp \
    server.cpp \
    servermain.cpp \
    serverworker.cpp \
    serverwindow.cpp \
    variant.cpp

FORMS += \
    serverwindow.ui
