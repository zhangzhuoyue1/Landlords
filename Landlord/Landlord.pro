QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CardPanel.cpp \
    cards.cpp \
    gamecontrol.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    robot.cpp \
    scorepanel.cpp \
    userplayer.cpp

HEADERS += \
    Card.h \
    CardPanel.h \
    Logger.h \
    cards.h \
    gamecontrol.h \
    mainwindow.h \
    player.h \
    robot.h \
    scorepanel.h \
    userplayer.h

FORMS += \
    mainwindow.ui \
    scorepanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
