#include "Source_Files/precompiled_header.h"
#include "game.h"

//Static functions

//Initialization functions
void Game::initVariables()
{
    this->window = NULL;
    this->dt = 0.f;
}

void Game::initGraphicSettings()
{
    this->graphicSettings.loadFromFile("Config/graphic_settings.ini");
}

void Game::initWindow()
{
    //Creates SFML window
    if(this->graphicSettings.fullscreen)
    {
        this->window = new sf::RenderWindow(
                    this->graphicSettings.resolution,
                    this->graphicSettings.title,
                    sf::Style::Fullscreen,
                    this->graphicSettings.contextSettings
                    );
    }
    else
    {
        this->window = new sf::RenderWindow(
                    this->graphicSettings.resolution,
                    this->graphicSettings.title,
                    sf::Style::Titlebar | sf::Style::Close,
                    this->graphicSettings.contextSettings
                    );
    }

    this->window->setFramerateLimit(this->graphicSettings.frameRateLimit);
    this->window->setVerticalSyncEnabled(this->graphicSettings.verticalSync);
}

void Game::initKeys()
{
    std::ifstream ifs("Config/supported_keys.ini");

    if(ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while(ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();

    //Debug - To be removed!
    for(auto i : this->supportedKeys)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}

void Game::initStateData()
{
    this->stateData.window = this->window;
    this->stateData.graphicsSettings = &this->graphicSettings;
    this->stateData.supportedKeys = &this->supportedKeys;
    this->stateData.states = &this->states;
}

void Game::initStates()
{
    this->states.push(new MainMenuState(&this->stateData));
}

//Constructors/Destructors
Game::Game()
{
    this->initVariables();
    this->initGraphicSettings();
    this->initWindow();
    this->initKeys();
    this->initStateData();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

//Fuctions

//Regular
void Game::endApplication()
{

}

//Update
void Game::updateDT()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while(this->window->pollEvent(this->sfEvent))
    {
        if(this->sfEvent.type==sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    if(!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //Application end
    else
    {
        this->endApplication();
        this->window->close();
    }
}

//Render
void Game::render()
{
    this->window->clear();

    //Render items
    if(!this->states.empty())
    {
        this->states.top()->render();
    }

    this->window->display();
}

//Core
void Game::run()
{
    while(this->window->isOpen())
    {
        this->updateDT();
        this->update();
        this->render();
    }
}
