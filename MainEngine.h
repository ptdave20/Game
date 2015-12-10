//
// Created by ptdave on 05/12/15.
//

#ifndef GAME_MAINENGINE_H
#define GAME_MAINENGINE_H

#include <iostream>
#include <array>
#include "game.h"
#include "scenes/ptDaveScene.h"
#include "scenes/MainMenu.h"

class MainEngine : public Game {
public:
    MainEngine();

    enum {
        UNINITIALIZED = -1,
        PRODUCEDBY = 0,
        MAINMENU = 1,
        GAME = 2
    } States;

protected:
    virtual void onUpdate(const sf::Time &time) override;
    virtual void onEvent(const sf::Event &event) override;
private:
    std::array<bool,sf::Keyboard::KeyCount> keys;
    int state;

    std::shared_ptr<Scene> m_producedBy;
    std::shared_ptr<Scene> m_mainMenu;
    std::shared_ptr<Scene> m_game;
};


#endif //GAME_MAINENGINE_H
