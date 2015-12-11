//
// Created by ptdave on 10/12/15.
//

#ifndef GAME_GUNSHOT_H
#define GAME_GUNSHOT_H


#include <SFML/Graphics/Sprite.hpp>

class GunShot : public sf::Sprite {
public:
    GunShot(const sf::Texture &texture);
    virtual int getDamage() const = 0;
    virtual bool isDone() const = 0;
};


#endif //GAME_GUNSHOT_H
