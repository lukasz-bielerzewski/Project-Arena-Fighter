TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
    Components/animationcomponent.cpp \
    Components/movementcomponent.cpp \
    Entities/entity.cpp \
    Entities/player.cpp \
    Resource_Files/button.cpp \
    Source_Files/Game.cpp \
    States/gamestate.cpp \
    States/mainmenustate.cpp \
    States/state.cpp \
    Source_Files/main.cpp \


HEADERS += \
    Components/animationcomponent.h \
    Components/movementcomponent.h \
    Entities/entity.h \
    Entities/player.h \
    Resource_Files/button.h \
    States/gamestate.h \
    States/mainmenustate.h \
    States/state.h \
    Source_Files/game.h \

