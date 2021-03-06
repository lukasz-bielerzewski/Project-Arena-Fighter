#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "Resource_Files/Gui.h"

class Button;

class PauseMenu
{
private:
    sf::Font &font;
    sf::Text menuText;

    sf::RectangleShape background;
    sf::RectangleShape container;

    std::map<std::string, gui::Button*> buttons;

    //Private functions

public:
    //Constructors / Destructors
    PauseMenu(sf::RenderWindow &window, sf::Font &font);
    virtual ~PauseMenu();

    //Accessors
    std::map<std::string, gui::Button*> &getButtons();

    //Functions
    bool isButtonPressed(const std::string key);
    void addButton(const std::string key, float y, const std::string text);
    void update(const sf::Vector2f &mousePos);
    void render(sf::RenderTarget &target);
};

#endif // PAUSEMENU_H
