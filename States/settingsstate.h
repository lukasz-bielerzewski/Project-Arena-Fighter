#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "state.h"
#include "Resource_Files/Gui.h"

class State;
class Button;
class DropDownList;

class SettingsState : public State
{
private:
    //Variables
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, gui::Button*> buttons;
    std::map<std::string, gui::DropDownList*> dropDownLists;

    sf::Text optionsText;

    std::vector<sf::VideoMode> modes;

    //Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initGui();
    void initText();

public:
    //Constructors / Destructors
    SettingsState(StateData *state_data);
    virtual ~SettingsState();

    //Accessors

    //Functions
    void updateInput(const float &dt);
    void updateGui(const float &dt);
    void update(const float &dt);
    void renderGui(sf::RenderTarget &target);
    void render(sf::RenderTarget *target = nullptr);
};

#endif // SETTINGSSTATE_H
