#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"

class GameState : public State
{
private:
    Player *player;

    //Functions
    void initKeybinds();
    void initTextures();
    void initPlayers();

public:
    //Constructors/Destructors
    GameState(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void updateInput(const float &dt);
    void update(const float &dt);
    void render(sf::RenderTarget *target = nullptr);
};

#endif // GAMESTATE_H
