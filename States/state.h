#ifndef STATE_H
#define STATE_H

#include "Resource_Files/graphicssettings.h"

class GraphicsSettings;
class State;

class StateData
{
public:
    //Constructors / Destructors
    StateData() {};

    //Variables
    sf::RenderWindow *window;
    GraphicsSettings *graphicsSettings;
    std::map<std::string, int>* supportedKeys;
    std::stack<State*> *states;
};

class State
{
private:

protected:
    //Variables
    StateData *stateData;
    std::stack<State*> *states;
    sf::RenderWindow *window;
    std::map<std::string, int> *supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;
    bool paused;
    float keytime;
    float keytimeMax;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Resources
    std::map<std::string, sf::Texture> textures;

    //Functions
    virtual void initKeybinds() = 0;

public:
    //Constructors/Destructors
    State(StateData *state_data);
    virtual ~State();

    //Accessors
    const bool &getQuit() const;
    bool getKeytime();

    //Functions
    void endState();
    void pauseState();
    void unpauseState();

    virtual void updateMousePositions();
    virtual void updateKeytime(const float &dt);
    virtual void updateInput(const float &dt) = 0;
    virtual void update(const float &dt) = 0;
    virtual void render(sf::RenderTarget *target = nullptr) = 0;
};

#endif // STATE_H
