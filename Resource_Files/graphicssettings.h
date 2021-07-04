#ifndef GRAPHICSETTINGS_H
#define GRAPHICSETTINGS_H


class GraphicsSettings
{
public:
    //Constructors / Destructors
    GraphicsSettings();
    virtual ~GraphicsSettings();

    //Variables
    std::string title;
    sf::VideoMode resolution;
    bool fullscreen;
    bool verticalSync;
    unsigned frameRateLimit;
    sf::ContextSettings contextSettings;
    std::vector<sf::VideoMode> videoModes;

    //Functions
    void saveToFile(const std::string path);
    void loadFromFile(const std::string path);
};

#endif // GRAPHICSETTINGS_H
