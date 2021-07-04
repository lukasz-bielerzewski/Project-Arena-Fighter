#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "Entities/player.h"
#include "Map/map.h"
#include "GUI/pausemenu.h"

class State;
class Player;
class Map;
class PauseMenu;

class GameState : public State
{
private:
    sf::Font font;
    PauseMenu *pmenu;

    Player *player;

    //Functions
    void initKeybinds();
    void initFonts();
    void initTextures();
    void initPauseMenu();
    void initPlayers();

public:
    //Constructors/Destructors
    GameState(StateData *state_data);
    virtual ~GameState();

    //Functions
    void updateInput(const float &dt);
    void updatePlayerInput(const float &dt);
    void updatePauseMenuButtons();
    void update(const float &dt);
    void render(sf::RenderTarget *target = nullptr);
};

#endif // GAMESTATE_H
