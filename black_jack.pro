TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        card.cpp \
        deck.cpp \
        main.cpp \
        participant.cpp

HEADERS += \
    card.h \
    constants.h \
    deck.h \
    participant.h
