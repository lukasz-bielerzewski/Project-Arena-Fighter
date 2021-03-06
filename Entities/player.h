#ifndef PLAYER_H
#define PLAYER_H

#include "Entities/entity.h"

class Entity;

class Player :
        public Entity
{
private:
    //Variables
    bool attacking;

    //Initializer functions
    void initVariables();
    void initComponents();

public:
    Player(float x, float y, sf::Texture &texture);
    virtual ~Player();

    //Functions
    void updateAttack();
    void updateAnimation(const float &dt);
    virtual void update(const float &dt);
};

#endif // PLAYER_H
