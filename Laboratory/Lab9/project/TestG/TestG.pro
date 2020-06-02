include(gtest_dependency.pri)

INCLUDEPATH += C:\Users\Mauz\Documents\TestG\projectForTesting

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        projectForTesting/IKeypad.h \
        projectForTesting/ILatch.h \
        projectForTesting/lockcontroller.h \
        tst_testdivisionbyzero.h

SOURCES += \
        main.cpp \
        projectForTesting/lockcontroller.cpp
