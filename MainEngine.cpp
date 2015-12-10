//
// Created by ptdave on 05/12/15.
//

#include "MainEngine.h"
#include "scenes/GameScene.h"
#include "config.h"
using namespace std;


MainEngine::MainEngine() : Game("game",game_DEFAULT_WIDTH,game_DEFAULT_HEIGHT,game_DEFAULT_BPP){
    state = MainEngine::UNINITIALIZED;
    m_producedBy = std::shared_ptr<Scene>(new ptDaveScene);
    m_mainMenu = std::shared_ptr<Scene>(new MainMenu);
    m_game = std::shared_ptr<Scene>(new GameScene);
}

void MainEngine::onUpdate(const sf::Time &time) {
    switch(state) {
        case UNINITIALIZED:
            state = PRODUCEDBY;
            setScene(m_producedBy);
            m_producedBy->init(this->getSize());
            break;
        case PRODUCEDBY:
            if(m_producedBy->isFinished()) {
                state = MAINMENU;
                setScene(m_mainMenu);
                m_mainMenu->init(this->getSize());
            }
            break;
        case MAINMENU:
            if(m_mainMenu->isFinished()) {
                switch(m_mainMenu->finishState()) {
                    case MainMenu::EXIT:
                        quit();
                        break;
                    case MainMenu::NEWGAME:
                        setScene(m_game);
                        state = GAME;
                        m_game->init(this->getSize());
                        break;
                    case MainMenu::OPTIONS:
                        break;
                }
            }
            break;
    }
}

void MainEngine::onEvent(const sf::Event &event) {
    if(event.type == sf::Event::KeyPressed) {
        keys[event.key.code] = true;
    }
    if(event.type == sf::Event::KeyReleased) {
        if(keys[event.key.code]) {
            if(event.key.code == sf::Keyboard::F1) {
                toggleFPS();
                cout << (getShowFPS() ? "true": "false") << endl;
            }
            if(event.key.code == sf::Keyboard::Escape) {
                quit();
            }
        }
        keys[event.key.code] = false;
    }
    if(hasScene()) {
        sendEventToScene(event);
    }
}
