TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
CONFIG   += console precompile_header

INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

PRECOMPILED_HEADER = Source_Files/precompiled_header.h

SOURCES += \
    Components/animationcomponent.cpp \
    Components/hitboxcomponent.cpp \
    Components/movementcomponent.cpp \
    Entities/entity.cpp \
    Entities/player.cpp \
    GUI/pausemenu.cpp \
    Map/map.cpp \
    Resource_Files/Gui.cpp \
    Resource_Files/graphicssettings.cpp \
    Source_Files/Game.cpp \
    States/gamestate.cpp \
    States/mainmenustate.cpp \
    States/settingsstate.cpp \
    States/state.cpp \
    Source_Files/main.cpp


HEADERS += \
    Components/animationcomponent.h \
    Components/hitboxcomponent.h \
    Components/movementcomponent.h \
    Entities/entity.h \
    Entities/player.h \
    GUI/pausemenu.h \
    Map/map.h \
    Resource_Files/Gui.h \
    Resource_Files/graphicssettings.h \
    Source_Files/precompiled_header.h \
    States/gamestate.h \
    States/mainmenustate.h \
    States/settingsstate.h \
    States/state.h \
    Source_Files/game.h

