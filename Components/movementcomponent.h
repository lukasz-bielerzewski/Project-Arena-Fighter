#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

enum movement_states {IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, BLOCKING, JUMPING_UP, JUMPING_LEFT, JUMPING_RIGHT, CROUCHING, CROUCHING_LEFT, CROUCHING_RIGHT, CROUCH_BLOCKING};

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
    const float &getMaxVelovity() const;
    const sf::Vector2f &getVelocity() const;

    //Functions
    bool getState(const short unsigned state) const;

    void move(const float dir_x, const float dir_y, const float &dt);
    void update(const float &dt);
};

#endif // MOVEMENTCOMPONENT_H
