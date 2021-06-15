#ifndef PLAYER_H
#define PLAYER_H

#include "Entities/entity.h"

class Player :
        public Entity
{
private:
    //Variables

    //Initializer functions
    void initVariables();
    void initComponents();

public:
    Player(float x, float y, sf::Texture &texture);
    virtual ~Player();

    //Functions
    virtual void update(const float &dt);
};

#endif // PLAYER_H