#ifndef ENTITY_H
#define ENTITY_H

#include "Components/movementcomponent.h"
#include "Components/animationcomponent.h"

class Entity
{
private:
    void initVariables();

protected:
    sf::Sprite sprite;

    MovementComponent *movementComponent;
    AnimationComponent *animationComponent;

public:
    //Constructors/Destructors
    Entity();
    virtual ~Entity();

    //Component functions
    void setTexture(sf::Texture &texture);
    void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
    void createAnimationComponent(sf::Texture &texture_sheet);

    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y, const float &dt);
    virtual void update(const float &dt);
    virtual void render(sf::RenderTarget *target);
};

#endif // ENTITY_H
