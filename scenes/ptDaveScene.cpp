//
// Created by ptdave on 06/12/15.
//

#include "ptDaveScene.h"
#include <iostream>

using namespace std;

void ptDaveScene::init(const sf::Vector2u &u) {
    if(load)
        return;
    totalTime = 0;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 0;
    logoSprite.setColor(color);
    if(!img.loadFromFile("./assets/ptdave.png")) {
        cout << "Unable to load ptdave.png";
    } else {
        float xScale = 1;
        float yScale = 1;
        auto imgSize = img.getSize();
        if(img.getSize().x > u.x || img.getSize().y > u.y) {
            xScale = (float)u.x/(float)imgSize.y;
            yScale = (float)u.x/(float)imgSize.x;
            if(xScale > yScale)
                xScale = yScale * 0.9;
            else
                yScale = xScale *0.9;
        }

        img.setSmooth(true);
        logoSprite.setTexture(img);
        logoSprite.scale(xScale, yScale);

        logoSprite.setOrigin(0,0);

        load = true;
    }
}

bool ptDaveScene::isFinished() const {
    return totalTime >= fadeInTime+fadeOutTime+solidTime;
}

int ptDaveScene::finishState() const {
    return 0;
}

void ptDaveScene::draw(sf::RenderTarget &render, sf::RenderStates states) const {
    render.draw(logoSprite);
}

ptDaveScene::ptDaveScene() {
    load = false;
    totalTime = 0;
    fadeInTime = 3;
    fadeOutTime = 1;
    solidTime = 3;
}

void ptDaveScene::handleEvent(const sf::Event &e) {
    if(e.type == sf::Event::Resized) {
        float xScale = 1;
        float yScale = 1;
        auto imgSize = img.getSize();
        auto u = sf::Vector2u(e.size.width,e.size.height);
        if(img.getSize().x > u.x || img.getSize().y > u.y) {
            xScale = (float)u.x/(float)imgSize.y;
            yScale = (float)u.x/(float)imgSize.x;
            if(xScale > yScale)
                xScale = yScale * 0.9;
            else
                yScale = xScale *0.9;
        }
        logoSprite.setScale(xScale,yScale);

        int xSize = imgSize.x * xScale;
        int ySize = imgSize.y * yScale;

        logoSprite.setPosition(u.x / 2 - xSize / 2,u.y / 2 - ySize / 2);
    }
}

void ptDaveScene::update(const sf::Time &time) {
    totalTime+=time.asSeconds();
    float v;
    // Fade in
    if(totalTime <= fadeInTime) {
        v = (totalTime / fadeInTime);
        color.a = 255*v;
    } else
        // Solid
        if(totalTime > fadeOutTime && totalTime <= fadeOutTime+solidTime) {
            color.a = 255;
        } else
            // Fade out
            if(totalTime >= fadeInTime+solidTime && totalTime < fadeInTime + fadeOutTime + solidTime) {
                v = (fadeInTime+solidTime+fadeOutTime) - totalTime;
                color.a = 255 * v;
            }
    logoSprite.setColor(color);
}
