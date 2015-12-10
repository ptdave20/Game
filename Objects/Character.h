//
// Created by ptdave on 08/12/15.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

class Character : public sf::Drawable {
public:
    Character();

    enum {
        MOVELEFT,MOVERIGHT,JUMP,FALL,DEAD,DAMAGED
    } States;

    virtual void init(const sf::Vector2u &screenSize) = 0;
    virtual void update(const sf::Time &t) = 0;
    virtual void draw(sf::RenderTarget &t, sf::RenderStates &s) const = 0;
    virtual void handleEvent(const sf::Event &e) = 0;
    virtual int getState() const =0;
};


#endif //GAME_CHARACTER_H
