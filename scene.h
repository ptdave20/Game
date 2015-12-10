#include <SFML/Graphics.hpp>
#include <memory>

#ifndef SCENE_H
#define SCENE_H


class Scene : public sf::Drawable
{
public:
    Scene(Scene *parent = nullptr);

    virtual void init(const sf::Vector2u &windowSize) = 0;
    virtual void update(const sf::Time&);
    virtual void handleEvent(const sf::Event&);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
    virtual bool isFinished() const = 0;
    virtual int finishState() const = 0;
};

#endif // SCENE_H
