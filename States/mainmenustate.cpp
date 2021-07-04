#include "Source_Files/precompiled_header.h"
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

    if(!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/menu_background.jpg"))
    {
        throw"ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
    }

    this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("Resources/Fonts/PressStart2P-Regular.ttf"))
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
    this->buttons["SINGLE_PLAYER_MODE"] = new gui::Button(
                200.f, 425.f, 350.f, 70.f,
                &this->font, "Single player mode", 14,
                sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200)
                );

    this->buttons["MULTIPLAYER_MODE"] = new gui::Button(
                200.f, 550.f, 350.f, 70.f,
                &this->font, "Multiplayer mode", 14,
                sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200)
                );

    this->buttons["SETTINGS"] = new gui::Button(
                200.f, 675.f, 350.f, 70.f,
                &this->font, "Settings", 14,
                sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200)
                );

    this->buttons["EXIT_STATE"] = new gui::Button(
                200.f, 825.f, 350.f, 70.f,
                &this->font, "Quit Game", 14,
                sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200)
                );
}

//Constructors / Destructors
MainMenuState::MainMenuState(StateData *state_data)
    : State(state_data)
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
        this->states->push(new GameState(this->stateData));
    }

    //Multiplayer mode
    if(this->buttons["MULTIPLAYER_MODE"]->isPressed())
    {
        //this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    //Settings
    if(this->buttons["SETTINGS"]->isPressed())
    {
        this->states->push(new SettingsState(this->stateData));
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

void MainMenuState::renderButtons(sf::RenderTarget &target)
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

    this->renderButtons(*target);

    //Tool for positioning buttons, to be removed later!
//    sf::Text mouseText;
//    mouseText.setPosition(this->mousePosView.x + 10.f, this->mousePosView.y);
//    mouseText.setFont(this->font);
//    mouseText.setCharacterSize(10);
//    std::stringstream ss;
//    ss << this->mousePosView.x << " " << this->mousePosView.y;
//    mouseText.setString(ss.str());

//    target->draw(mouseText);
}
