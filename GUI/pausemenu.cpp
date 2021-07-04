#include "Source_Files/precompiled_header.h"
#include "pausemenu.h"

//Constructors / Destructors
PauseMenu::PauseMenu(sf::RenderWindow &window, sf::Font &font)
    : font(font)
{
    //Init background
    this->background.setSize(
                sf::Vector2f(
                    static_cast<float>(window.getSize().x),
                    static_cast<float>(window.getSize().y)
                    )
                             );
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    //Init container
    this->container.setSize(
                sf::Vector2f(
                    static_cast<float>(window.getSize().x) / 4.f,
                    static_cast<float>(window.getSize().y) - 200.f
                    )
                            );
    this->container.setFillColor(sf::Color(20, 20, 20, 200));
    this->container.setPosition(
                static_cast<float>(window.getSize().x) / 2.f -this->container.getSize().x / 2.f,
                100.f
                );

    //Init text
    this->menuText.setFont(font);
    this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
    this->menuText.setCharacterSize(40);
    this->menuText.setString("PAUSED");
    this->menuText.setPosition(
                this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
                this->container.getPosition().y + 40.f
                );
}

PauseMenu::~PauseMenu()
{
    auto it = this->buttons.begin();
    for(it = this->buttons.begin(); it != this->buttons.end(); ++it)
    {
        delete it->second;
    }
}

//Accessors
std::map<std::string, gui::Button *> &PauseMenu::getButtons()
{
    return this->buttons;
}

//Functions
bool PauseMenu::isButtonPressed(const std::string key)
{
    return this->buttons[key]->isPressed();
}

void PauseMenu::addButton(const std::string key, float y, const std::string text)
{
    float width = 350.f;
    float height = 70.f;
    float x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;

    this->buttons[key] = new gui::Button(
                x, y, width, height,
                &this->font, text, 14,
                sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200)
                );
}

void PauseMenu::update(const sf::Vector2f &mousePos)
{
    for(auto &i : this->buttons)
    {
        i.second->update(mousePos);
    }
}

void PauseMenu::render(sf::RenderTarget &target)
{
    target.draw(this->background);
    target.draw(this->container);

    for(auto &i : this->buttons)
    {
        i.second->render(target);
    }

    target.draw(this->menuText);
}
