#include "Source_Files/precompiled_header.h"
#include "settingsstate.h"

//Initialzer functions
void SettingsState::initVariables()
{
    this->modes = sf::VideoMode::getFullscreenModes();
}

void SettingsState::initBackground()
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

void SettingsState::initFonts()
{
    if(!this->font.loadFromFile("Resources/Fonts/PressStart2P-Regular.ttf"))
    {
        throw("ERROR::MAIN_MENU_STATE::COULD_NOT_LOAD_FONT");
    }
}

void SettingsState::initKeybinds()
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

void SettingsState::initGui()
{
    this->buttons["BACK_TO_MAIN_MENU"] = new gui::Button(
                525.f, 900.f, 350.f, 70.f,
                &this->font, "Back to main menu", 14,
                sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200)
                );

    this->buttons["APPLY_SETTINGS"] = new gui::Button(
                125.f, 900.f, 350.f, 70.f,
                &this->font, "Apply settings", 14,
                sf::Color(240, 240, 240, 255), sf::Color(255, 255, 255, 255), sf::Color(100, 100, 100, 255),
                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 250, 255), sf::Color(20, 20, 20, 200)
                );

    std::vector<std::string> modes_str;

    for(auto &i : this->modes)
    {
        modes_str.push_back(std::to_string(i.width) + " x " + std::to_string(i.height));
    }

    this->dropDownLists["RESOLUTION"] = new gui::DropDownList(575.f, 285.f, 250.f, 50.f, font, modes_str.data(), modes_str.size());
}

void SettingsState::initText()
{
    this->optionsText.setFont(this->font);
    this->optionsText.setPosition(sf::Vector2f(125.f, 300.f));
    this->optionsText.setCharacterSize(30.f);
    this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));

    this->optionsText.setString(
                "Resolution \n\n\nFullscreen \n\n\nVsync \n\n\nAntialiasing"
);
}


//Constructors / Destructors
SettingsState::SettingsState(StateData *state_data)
    : State(state_data)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initGui();
    this->initText();
}

SettingsState::~SettingsState()
{
    auto it = this->buttons.begin();
    for(it = this->buttons.begin(); it != this->buttons.end(); ++it)
    {
        delete it->second;
    }

    auto it2 = this->dropDownLists.begin();
    for(it2 = this->dropDownLists.begin(); it2 != this->dropDownLists.end(); ++it2)
    {
        delete it2->second;
    }
}

//Accessors

//Functions
void SettingsState::updateInput(const float &dt)
{

}

void SettingsState::updateGui(const float &dt)
{
    //Updates all the gui elements and theirs functionality
    //Buttons
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

    //Buttons functionality
    //Quit the game
    if(this->buttons["BACK_TO_MAIN_MENU"]->isPressed())
    {
        this->endState();
    }

    //Apply selected settings
    if(this->buttons["APPLY_SETTINGS"]->isPressed())
    {
        this->stateData->graphicsSettings->resolution = modes[this->dropDownLists["RESOLUTION"]->getActiveElementId()];

        //TEST TO BE REMOVED LATER
        this->window->create(this->stateData->graphicsSettings->resolution, this->stateData->graphicsSettings->title, sf::Style::Default);
    }

    //Dropdown lists
    for(auto &it : this->dropDownLists)
    {
        it.second->update(this->mousePosView, dt);
    }

    //Dropdown lists functionality
}

void SettingsState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->updateGui(dt);
}

void SettingsState::renderGui(sf::RenderTarget &target)
{
    //Render buttons
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }

    //Render dropdown lits
    for(auto &it : this->dropDownLists)
    {
        it.second->render(target);
    }
}

void SettingsState::render(sf::RenderTarget *target)
{
    if(!target)
    {
        target = this->window;
    }
    target->draw(this->background);

    this->renderGui(*target);

    target->draw(this->optionsText);

    //Tool for positioning buttons, to be removed later!
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x + 10.f, this->mousePosView.y);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(10);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());

    target->draw(mouseText);
}
