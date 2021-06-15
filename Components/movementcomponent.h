#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>


class MovementComponent
{
private:
    sf::Sprite &sprite;

    //Variables
    float maxVelocity;
    float acceleration;
    float deceleration;

    sf::Vector2f velocity;

    //Initializer functions

public:
    //Constructors / Destructors
    MovementComponent(sf::Sprite &sprite, float maxVelocity, float acceleration, float deceleration);
    virtual ~MovementComponent();

    //Accessors
    const sf::Vector2f &getVelocity() const;

    //Functions
    bool idle() const;

    void move(const float dir_x, const float dir_y, const float &dt);
    void update(const float &dt);
};

#endif // MOVEMENTCOMPONENT_H
