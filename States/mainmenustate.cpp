#include "mainmenustate.h"

//Initialzer functions
void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
    this->background.setSize(sf::Vector2f
          (static_cast<float>(this->window->getSize().x),
          static_cast<float>(this->window->getSize().y)));

    if(!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/placeholder_background.jpg"))
    {
        throw"ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
    }

    this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("Fonts/PressStart2P-Regular.ttf"))
    {
        throw("ERROR::MAIN_MENU_STATE::COULD_NOT_LOAD_FONT");
    }
}

void MainMenuState::initKeybinds()
{
    std::ifstream ifs("Config/mainmenustate_keybinds.ini");

    if(ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while(ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();
}

void MainMenuState::initButtons()
{
    this->buttons["SINGLE_PLAYER_MODE"] = new Button(200, 425, 350, 70,
        &this->font, "Single player mode", 14,
        sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200));

    this->buttons["MULTIPLAYER_MODE"] = new Button(200, 550, 350, 70,
        &this->font, "Multiplayer mode", 14,
        sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200));

    this->buttons["SETTINGS"] = new Button(200, 675, 350, 70,
        &this->font, "Settings", 14,
        sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200));

    this->buttons["EXIT_STATE"] = new Button(200, 825, 350, 70,
        &this->font, "Quit Game", 14,
        sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
        sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200));
}

//Constructors/Destructors
MainMenuState::MainMenuState(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
}

MainMenuState::~MainMenuState()
{
    auto it = this->buttons.begin();
    for(it = this->buttons.begin(); it != this->buttons.end(); ++it)
    {
        delete it->second;
    }
}

//Functions
void MainMenuState::updateInput(const float &dt)
{

}

void MainMenuState::updateButtons()
{
    //Updates all the buttons and theirs functionality
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

    //Single player mode
    if(this->buttons["SINGLE_PLAYER_MODE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    //Multiplayer mode
    if(this->buttons["MULTIPLAYER_MODE"]->isPressed())
    {
        //this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    //Settings
    if(this->buttons["SETTINGS"]->isPressed())
    {
        //this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    //Quit the game
    if(this->buttons["EXIT_STATE"]->isPressed())
    {
        this->endState();
    }
}

void MainMenuState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget *target)
{
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget *target)
{
    if(!target)
    {
        target = this->window;
    }
    target->draw(this->background);

    this->renderButtons(target);

    //To be removed later!
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x + 10.f, this->mousePosView.y);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(10);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());

    target->draw(mouseText);
}
