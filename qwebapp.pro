#-------------------------------------------------
#
# Project created by QtCreator 2011-09-26T19:54:53
#
#-------------------------------------------------

QT       += core \
            gui \
            webkit

CONFIG += qt \
          clang \
#          gcc \
          warn_on \
#          release
          debug

TARGET = qwebapp
TEMPLATE = app

SOURCES += main.cpp\
           mainwindow.cpp \
           session_manager.cpp

HEADERS  += mainwindow.hpp \
            session_manager.hpp

OBJECTS_DIR = /tmp/
MOC_DIR = /tmp/

RELEASEFLAGS += -O3 \
                -fomit-frame-pointer \
                -march=x86-64 \
                -ffast-math
CONFIG(clang) {
    RELEASEFLAGS += -flto \
                    -fwhole-program \
                    -O4
}

DEBUGFLAGS += -O0 \
              -ggdb \
              -pedantic \
              -W \
              -Wall \
              -Wextra \
              -Wuninitialized \
              -Wshadow \
              -Wsign-compare \
              -Wwrite-strings \
              -Wunused \
              -Wfloat-equal \
              -Wmissing-declarations \
              -Wunreachable-code \
              -Wcast-qual \
              -ftrapv
CONFIG(clang) {
    DEBUGFLAGS += -fcatch-undefined-behavior
}

QMAKE_CFLAGS_GENERIC += -std=c99 \
                        -Wc++-compat \
                        -pipe
QMAKE_CXXFLAGS_GENERIC += -std=c++98 \
                          -pipe

QMAKE_CFLAGS_RELEASE =   $$QMAKE_CFLAGS_GENERIC   $$RELEASEFLAGS
QMAKE_CFLAGS_DEBUG =     $$QMAKE_CFLAGS_GENERIC   $$DEBUGFLAGS
QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CXXFLAGS_GENERIC $$RELEASEFLAGS
QMAKE_CXXFLAGS_DEBUG =   $$QMAKE_CXXFLAGS_GENERIC $$DEBUGFLAGS

QMAKE_LFLAGS_RELEASE = $$RELEASEFLAGS
QMAKE_LFLAGS_DEBUG =   $$DEBUGFLAGS

QMAKE_CC = gcc
QMAKE_CXX = g++
CONFIG(clang) {
    QMAKE_CC = clang
    QMAKE_CXX = clang
}

#GENERATED BY: gcc -v -x c++ /dev/null -fsyntax-only
INCLUDEPATH += /usr/include/c++/4.5 \
 /usr/include/c++/4.5/i686-linux-gnu \
 /usr/include/c++/4.5/backward \
 /usr/local/include \
 /usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5.2/include \
 /usr/lib/i386-linux-gnu/gcc/i686-linux-gnu/4.5.2/include-fixed \
 /usr/include/i386-linux-gnu \
 /usr/include
