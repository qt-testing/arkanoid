QT += widgets

CONFIG += release

SOURCES += control/control.cpp \
           gameplay/animation.cpp \
           gameplay/arkanoid.cpp \
           gameplay/box.cpp \
           gameplay/boxitem.cpp \
           gameplay/padboxitem.cpp \
           graphics/arkwidget.cpp \
           graphics/drawer.cpp \
           main.cpp \
           mainwindow.cpp

HEADERS += control/control.h \
           gameplay/animation.h \
           gameplay/arkanoid.h \
           gameplay/box.h \
           gameplay/boxitem.h \
           gameplay/padboxitem.h \
           graphics/arkwidget.h \
           graphics/drawer.h \
           mainwindow.h

FORMS += mainwindow.ui

INCLUDEPATH += control \
               gameplay \
               graphics
