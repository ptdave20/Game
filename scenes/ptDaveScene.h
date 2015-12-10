//
// Created by ptdave on 06/12/15.
//

#ifndef GAME_PTDAVESCENE_H
#define GAME_PTDAVESCENE_H


#include "../scene.h"

class ptDaveScene : public Scene {
public:
    ptDaveScene();

    void init(const sf::Vector2u &u);
    void draw(sf::RenderTarget &render, sf::RenderStates) const;
    void update(const sf::Time &time);
    void handleEvent(const sf::Event &e);
    bool isFinished() const;
    int finishState() const;
protected:
    sf::Sprite logoSprite;
    sf::Texture img;
    sf::Color color;
    float totalTime;
    bool load;

    int fadeInTime;
    int fadeOutTime;
    int solidTime;
};


#endif //GAME_PTDAVESCENE_H
