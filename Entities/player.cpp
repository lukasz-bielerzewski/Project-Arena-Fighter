#include "player.h"

//Initializer functions
void Player::initVariables()
{

}

void Player::initComponents()
{

}

//Constructors/Deconstructors
Player::Player(float x, float y, sf::Texture &texture_sheet)
{
    this->initVariables();

    this->setPosition(x, y);

    this->createMovementComponent(200.f, 10.f, 6.f);
    this->createAnimationComponent(texture_sheet);

    this->animationComponent->addAnimation("IDLE_LEFT", 10.f, 0, 0, 3, 0, 192, 192);
    this->animationComponent->addAnimation("WALK_LEFT", 10.f, 0, 1, 11, 1, 192, 192);
}

Player::~Player()
{

}

//Functions
void Player::update(const float &dt)
{
    this->movementComponent->update(dt);

    if(this->movementComponent->idle())
    {
        this->animationComponent->play("IDLE_LEFT", dt);
    }
    else
    {
        this->animationComponent->play("WALK_LEFT", dt);
    }
}