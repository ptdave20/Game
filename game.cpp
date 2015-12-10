#include "game.h"
#include "config.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <assert.h>
#include <memory>

using namespace std;
Game::Game(const char *name, int width, int height, int bpp) : sf::RenderWindow(sf::VideoMode(width,height,bpp),name)
{
    clear(sf::Color::Black);
    fps = false;
}

void Game::run() {
    sf::Event event;
    int frames = 0;
    
    if(game_DEFAULT_FRAMELIMIT != -1) {
        this->setFramerateLimit(game_DEFAULT_FRAMELIMIT);
    }
    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("./assets/arial.ttf"))
    {
        // error...
    }
    text.setColor(sf::Color::White);
    text.setFont(font);
    text.setCharacterSize(20);
    running = true;
    render = true;
    while(this->isOpen() && running) {
        while(pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    quit();
                    break;
                case sf::Event::Resized:
                    setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                    break;
            }
            onEvent(event);
        }
        if(render) {
            clear();


            m_Tick = m_Clock.restart();


            onUpdate(m_Tick);
            if(m_Scene) {
                m_Scene->update(m_Tick);
            }


            std::lock_guard<std::mutex> lock(m_Mutex);
            if(m_Scene) {
                draw(*m_Scene);
            }

            if(fps) {

                frames++;
                if (m_FPSClock.getElapsedTime().asMilliseconds() >= 1000) {
                    m_FPSClock.restart();
                    std::stringstream out;
                    out << frames;
                    text.setString(out.str());
                    frames = 0;
                }
                draw(text);
            }
            display();
        }
    }
    if(m_Scene)
        m_Scene.reset();
}

void Game::setScene(std::shared_ptr<Scene> &s)
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_Scene = s;
}

void Game::onUpdate(const sf::Time &time)
{

}

void Game::onEvent(const sf::Event &event)
{

}

void Game::toggleFPS() {
    fps = !fps;
}

void Game::quit() {
    running = false;
    render = false;
    close();
}

bool Game::isRendering() {
    return render;
}

bool Game::isRunning() {
    return running;
}

bool Game::getShowFPS() {
    return fps;
}

void Game::setShowFPS(const bool &v) {
    fps = true;
}

void Game::onQuit() {

}

bool Game::hasScene() const {
    return (bool)m_Scene;
}

void Game::sendEventToScene(const sf::Event &e) {
    m_Scene->handleEvent(e);
}
