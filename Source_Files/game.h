#ifndef GAME_H
#define GAME_H

#include "States/mainmenustate.h"
#include "Resource_Files/graphicssettings.h"

class MainMenuState;
class GraphicsSettings;

class Game
{
private:
    //Variables
    GraphicsSettings graphicSettings;
    StateData stateData;
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    std::map<std::string, int> supportedKeys;

    //Initialization
    void initVariables();
    void initGraphicSettings();
    void initWindow();
    void initKeys();
    void initStateData();
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
