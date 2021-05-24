QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    InMemoryDataBase.cpp \
    Question.cpp \
    Quiz.cpp \
    Round.cpp \
    Variant.cpp \
    aboutwindow.cpp \
    currentratingform.cpp \
    filereaderwriter.cpp \
    main.cpp \
    mainwindow.cpp \
    playernameform.cpp \
    questionform.cpp \
    quizselectionwindow.cpp \
    userresults.cpp

HEADERS += \
    Controller.h \
    InMemoryDataBase.h \
    QuizHeader.h \
    Round.h \
    aboutwindow.h \
    currentratingform.h \
    filereaderwriter.h \
    mainwindow.h \
    playernameform.h \
    questionform.h \
    quizselectionwindow.h \
    userresults.h

FORMS += \
    aboutwindow.ui \
    currentratingform.ui \
    mainwindow.ui \
    playernameform.ui \
    questionform.ui \
    quizselectionwindow.ui \
    userresults.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
