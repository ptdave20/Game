//
// Created by ptdave on 08/12/15.
//

#include "GameScene.h"
#include <iostream>
using namespace std;
void GameScene::init(const sf::Vector2u &windowSize) {
    window = windowSize;
    if(!particle.loadFromFile("./assets/particle.png")) {
        cout << "Unable to load particle" << endl;
    } else {
        for(auto &p : particleBG) {
            p.setTexture(particle);
            p.setPosition(rand()%window.x, rand()%window.y);
            auto c = sf::Color::White;

            c.a = (rand()%150)+25;
            p.setColor(c);

        }
    }

    if(!spaceship.loadFromFile("./assets/spaceship.png")) {
        cout << "Unable to load spaceship" << endl;
    } else {
        player.setTexture(spaceship);
        player.setPosition(window.x/2 - spaceship.getSize().x / 2, window.y - spaceship.getSize().y);
    }
}

void GameScene::update(const sf::Time &time1) {
    for(sf::Sprite &p : particleBG) {
        auto pos = p.getPosition();
        pos.y += time1.asSeconds() * (window.y / 10);
        if(pos.y >= window.y) {
            pos.y = 0;
            pos.x = rand()%window.x;
        }
        p.setPosition(pos);
    }
}

void GameScene::handleEvent(const sf::Event &event) {
    if(event.type == sf::Event::Resized) {

        auto xMult = (float)window.x / (float)event.size.width;
        auto yMult = (float)window.y / (float)event.size.height;
        auto xDiff = event.size.width - window.x;
        auto yDiff = event.size.height - window.y;

        window.x = event.size.width;
        window.y = event.size.height;

        for(sf::Sprite &p : particleBG) {
            auto pos = p.getPosition();
            pos.x *= xMult;
            pos.y *= yMult;
            p.setPosition(pos);
        }

        auto pPos = player.getPosition();
        pPos.x*=xMult;
        pPos.y*=yMult;

        cout << "playerPos = " << pPos.x <<"x"<<pPos.y << endl;

        player.setPosition(pPos);
    }
}

void GameScene::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    for(sf::Sprite p : particleBG) {
        target.draw(p,sf::BlendMode::BlendAlpha);
    }
    target.draw(player);
}

bool GameScene::isFinished() const {
    return false;
}

int GameScene::finishState() const {
    return 0;
}
