//
// Created by ptdave on 07/12/15.
//

#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu() {
    m_State = UNKNOWN;
}

void MainMenu::init(const sf::Vector2u &windowSize) {
    if(!m_Font.loadFromFile("./assets/arial.ttf")) {
        std::cout << "unable to load arial.ttf" << std::endl;
    }


    m_NewGameText.setColor(sf::Color::White);
    m_NewGameText.setFont(m_Font);
    m_NewGameText.setCharacterSize(30);
    m_NewGameText.setString("New Game");

    m_OptionText.setString("Options");
    m_OptionText.setCharacterSize(30);
    m_OptionText.setFont(m_Font);
    m_OptionText.setColor(sf::Color::White);

    m_QuitText.setString("Quit");
    m_QuitText.setCharacterSize(30);
    m_QuitText.setFont(m_Font);
    m_QuitText.setColor(sf::Color::White);
    alignText(windowSize);
}

bool MainMenu::isFinished() const {
    return m_State != -1;
}

int MainMenu::finishState() const {
    return m_State;
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_NewGameText);
    target.draw(m_OptionText);
    target.draw(m_QuitText);
}

void MainMenu::update(const sf::Time &time1) {
}

void MainMenu::handleEvent(const sf::Event &event) {
    if(event.type == sf::Event::Resized) {
        alignText(sf::Vector2u(event.size.width,event.size.height));
    }
    if(event.type == sf::Event::MouseButtonPressed) {
        mouseOver(m_NewGameText,event.mouseButton.x,event.mouseButton.y,sf::Color::Red,sf::Color::White);
        mouseOver(m_OptionText,event.mouseButton.x,event.mouseButton.y,sf::Color::Red,sf::Color::White);
        mouseOver(m_QuitText,event.mouseButton.x,event.mouseButton.y,sf::Color::Red,sf::Color::White);
    }
    if(event.type == sf::Event::MouseButtonReleased) {
        if(mouseOver(m_NewGameText,event.mouseButton.x,event.mouseButton.y,sf::Color::White,sf::Color::White)) {
            m_State = NEWGAME;
        }
        if(mouseOver(m_OptionText,event.mouseButton.x,event.mouseButton.y,sf::Color::White,sf::Color::White)) {
            m_State = OPTIONS;
        }
        if(mouseOver(m_QuitText,event.mouseButton.x,event.mouseButton.y,sf::Color::White,sf::Color::White)) {
            m_State = EXIT;
        }
    }
}

void MainMenu::alignText(const sf::Vector2u &u) {
    int size = u.y / 10;
    int halfY = u.y / 2;
    int spaceY = size / 5;
    m_NewGameText.setCharacterSize(size);
    m_OptionText.setCharacterSize(size);
    m_QuitText.setCharacterSize(size);

    m_NewGameText.setPosition(u.x / 2 - m_NewGameText.getLocalBounds().width/2,halfY);
    m_OptionText.setPosition(u.x / 2 - m_OptionText.getLocalBounds().width / 2, m_NewGameText.getPosition().y + m_NewGameText.getLocalBounds().height + spaceY);
    m_QuitText.setPosition(u.x / 2 - m_QuitText.getLocalBounds().width / 2, m_OptionText.getPosition().y + m_QuitText.getLocalBounds().height + spaceY);
}

bool MainMenu::mouseOver(sf::Text &t, const int &x, const int &y, const sf::Color &isTrue, const sf::Color &isFalse) {
    auto v = t.getGlobalBounds().contains(x,y);
    t.setColor( v ? isTrue : isFalse);
    return v;
}
