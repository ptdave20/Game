#include <vector>
#include <SFML/Graphics.hpp>

#ifndef OBJECTGROUP_H
#define OBJECTGROUP_H


class ObjectGroup : public sf::Drawable,public std::vector<sf::Drawable*>
{
public:
    ObjectGroup();
    ~ObjectGroup();

    virtual void draw(sf::RenderTarget &,sf::RenderStates) const;
    void render(sf::RenderTarget &target, sf::RenderStates state) const;
private:
};

#endif // OBJECTGROUP_H
