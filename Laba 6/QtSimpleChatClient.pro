QT += core network gui widgets

TARGET = QtSimpleChatClient
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


CONFIG += debug_and_release

SOURCES += \
    client.cpp \
    clientmain.cpp \
    clientwindow.cpp \
    question.cpp \
    questionform.cpp \
    quiz.cpp \
    variant.cpp

FORMS += \
    clientwindow.ui \
    questionform.ui

HEADERS += \
    client.h \
    clientwindow.h \
    question.h \
    questionform.h \
    quiz.h \
    variant.h
