//
// Created by ptdave on 07/12/15.
//

#ifndef GAME_MAINMENU_H
#define GAME_MAINMENU_H


#include "../scene.h"

class MainMenu : public Scene {
public:
    MainMenu();
    virtual void init(const sf::Vector2u &windowSize);
    virtual bool isFinished() const;
    virtual int finishState() const;
    enum {
        UNKNOWN = -1,
        NEWGAME = 0,
        OPTIONS = 1,
        EXIT = 2
    } RETURNSTATES;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual void update(const sf::Time &time1) override;

    virtual void handleEvent(const sf::Event &event) override;
private:
    bool mouseOver(sf::Text &t, const int &x, const int &y, const sf::Color &isTrue, const sf::Color &isFalse);
    void alignText(const sf::Vector2u &u);
    int m_State;
    bool m_assetsLoaded;
    sf::Text m_NewGameText;
    sf::Text m_OptionText;
    sf::Text m_QuitText;
    sf::Font m_Font;
};


#endif //GAME_MAINMENU_H
