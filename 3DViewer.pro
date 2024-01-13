QT       += core gui openglwidgets
win32: LIBS += -lopengl32
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TEMPLATE = app
TARGET = 3DViewer_v2.0

SOURCES += \
    main.cpp \
    view/s21_view.cpp \
    controller/s21_strategy.cpp \
    controller/s21_opengl.cpp \
    model/s21_model.cpp \
    controller/s21_controller.cpp
    

HEADERS += \
    view/s21_view.h \
    controller/s21_strategy.h \
    controller/s21_opengl.h \
    model/s21_model.h \
    controller/s21_controller.h
    

FORMS += \
    view/view.ui

# DESTDIR = ../build

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
