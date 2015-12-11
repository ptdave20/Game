//
// Created by ptdave on 08/12/15.
//

#ifndef GAME_GAMESCENE_H
#define GAME_GAMESCENE_H

#include "../scene.h"

class GameScene : public Scene {
public:
    virtual void init(const sf::Vector2u& windowSize) override;
    virtual void update(const sf::Time & time1) override;
    virtual void handleEvent(const sf::Event & event) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual bool isFinished() const override;
    virtual int finishState() const override;

private:
    sf::Texture particle;
    sf::Texture spaceship;
    sf::Sprite particleBG[25];
    sf::Sprite player;
    sf::Vector2u window;
    sf::Vector2u moveTo;

    int shipRateOfFire,shipDamage;
    int shipShields,shipArmor;
};


#endif //GAME_GAMESCENE_H
