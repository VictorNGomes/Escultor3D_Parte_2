TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cutbox.cpp \
        cutellipsoid.cpp \
        cutsphere.cpp \
        cutvoxel.cpp \
        interpretador.cpp \
        main.cpp \
        putbox.cpp \
        putellipsoid.cpp \
        putsphere.cpp \
        putvoxel.cpp \
        sculptor.cpp

HEADERS += \
    cutbox.h \
    cutellipsoid.h \
    cutsphere.h \
    cutvoxel.h \
    figurageometrica.h \
    interpretador.h \
    putbox.h \
    putellipsoid.h \
    putsphere.h \
    putvoxel.h \
    sculptor.h

DISTFILES += \
    patinete.txt
