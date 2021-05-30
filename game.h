#ifndef GAME_H
#define GAME_H

#include "States/gamestate.h"

class Game
{
private:
    //Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    //Initialization
    void initWindow();
    void initStates();

public:
    //Constructors/Destructors
    Game();
    virtual ~Game();

    //Accesors

    //Setters

    //Functions

    //Regular
    void endApplication();

    //Update
    void updateDT();
    void updateSFMLEvents();
    void update();

    //Render
    void render();

    //Core
    void run();
};

#endif // GAME_H
