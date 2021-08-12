TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        interpretador.cpp \
        main.cpp \
        putvoxel.cpp \
        sculptor.cpp

HEADERS += \
    cutvoxel.h \
    figurageometrica.h \
    interpretador.h \
    putvoxel.h \
    sculptor.h
