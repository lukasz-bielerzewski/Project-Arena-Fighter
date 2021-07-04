#include "Source_Files/precompiled_header.h"
#include "movementcomponent.h"

//Constructors / Destructors
MovementComponent::MovementComponent(sf::Sprite &sprite,
                   float maxVelocity, float acceleration, float deceleration)
    : sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{

}

//Accessors
const float &MovementComponent::getMaxVelovity() const
{
    return this->maxVelocity;
}

const sf::Vector2f &MovementComponent::getVelocity() const
{
    return this->velocity;
}

//Functions
bool MovementComponent::getState(const unsigned short state) const
{
    switch(state)
    {
    case IDLE:
    {
        if(this->velocity.x == 0.f && this->velocity.y == 0.f)
        {
            return true;
        }

        break;
    }
    case MOVING:
    {
        if(this->velocity.x != 0.f || this->velocity.y != 0.f)
        {
            return true;
        }

        break;
    }
    case MOVING_LEFT:
    {
        if(this->velocity.x < 0.f)
        {
            return true;
        }

        break;
    }
    case MOVING_RIGHT:
    {
        if(this->velocity.x > 0.f)
        {
            return true;
        }

        break;
    }
    case BLOCKING:
    {
        break;
    }
    case JUMPING_UP:
    {
        //testing
        if(this->velocity.y < 0.f)
        {
            return true;
        }

        break;
    }
    case JUMPING_LEFT:
    {
        break;
    }
    case JUMPING_RIGHT:
    {
        break;
    }
    case CROUCHING:
    {
        //testing
        if(this->velocity.y > 0.f)
        {
            return true;
        }

        break;
    }
    case CROUCHING_LEFT:
    {
        break;
    }
    case CROUCHING_RIGHT:
    {
        break;
    }
    case CROUCH_BLOCKING:
    {
        break;
    }
    }
    return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float &dt)
{
    /*Accelerating sprite until it reaches max velocity*/

    this->velocity.x += this->maxVelocity * dir_x;
    this->velocity.y += this->maxVelocity * dir_y;
}

void MovementComponent::update(const float &dt)
{
    /*
     Decelerates the sprite and controls max velocity.
     Then moves the sprite.
     */
    if(this->velocity.x > 0.f) //Check for positive x
    {
        //Max velocity check
        if(this->velocity.x > this->maxVelocity)
        {
            this->velocity.x = this->maxVelocity;
        }

        //Deceleration
        this->velocity.x -= deceleration;
        if(this->velocity.x < 0.f)
        {
            this->velocity.x = 0.f;
        }
    }
    else if(this->velocity.x < 0.f)//Check for negative x
    {
        //Max velocity check
        if(this->velocity.x < -this->maxVelocity)
        {
            this->velocity.x = -this->maxVelocity;
        }

        //Deceleration
        this->velocity.x += deceleration;
        if(this->velocity.x > 0.f)
        {
            this->velocity.x = 0.f;
        }
    }

    if(this->velocity.y > 0.f) //Check for positive y
    {
        //Max velocity check
        if(this->velocity.y > this->maxVelocity)
        {
            this->velocity.y = this->maxVelocity;
        }

        //Deceleration
        this->velocity.y -= deceleration;
        if(this->velocity.y < 0.f)
        {
            this->velocity.y = 0.f;
        }
    }
    else if(this->velocity.y < 0.f)//Check for negative y
    {
        //Max velocity check
        if(this->velocity.y < -this->maxVelocity)
        {
            this->velocity.y = -this->maxVelocity;
        }

        //Deceleration
        this->velocity.y += deceleration;
        if(this->velocity.y > 0.f)
        {
            this->velocity.y = 0.f;
        }
    }

    //Final move
    this->sprite.move(this->velocity * dt);
}
