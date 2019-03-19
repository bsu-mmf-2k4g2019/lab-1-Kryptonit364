QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = LW1
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

SOURCES += \
    main.cpp \
    button.cpp \
    lw.cpp

HEADERS += \
    button.h \
    lw.h

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
