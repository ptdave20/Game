#include <SFML/Graphics.hpp>
#include <memory>
#include <mutex>
#include "scene.h"

#ifndef GAME_H
#define GAME_H

class Game : public sf::RenderWindow
{
public:
    Game(const char* name, int width, int height, int bpp);
    void run();
    void setScene(std::shared_ptr<Scene> &s);
    void toggleFPS();
    bool getShowFPS();
    void setShowFPS(const bool &v);

    bool isRunning();
    bool isRendering();
    void quit();
    bool hasScene() const;
    void sendEventToScene(const sf::Event &e);
protected:
    virtual void onUpdate(const sf::Time &time);
    virtual void onEvent(const sf::Event &event);
    virtual void onQuit();
private:
    sf::Clock m_Clock;
    sf::Time m_Tick;
    sf::Clock m_FPSClock;
    std::shared_ptr<Scene> m_Scene;
    std::mutex m_Mutex;
    bool fps;
    bool render;
    bool running;
};

#endif // GAME_H
