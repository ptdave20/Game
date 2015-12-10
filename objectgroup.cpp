#include "objectgroup.h"

ObjectGroup::ObjectGroup() : sf::Drawable() , std::vector<Drawable*>()
{

}

ObjectGroup::~ObjectGroup() {
    for(std::vector<sf::Drawable*>::iterator i = begin(); i != end(); ++i) {
        delete *i;
    }
}

void ObjectGroup::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    for(std::vector<sf::Drawable*>::const_reference itr : *this) {
        target.draw(*itr,state);
    }
}

void ObjectGroup::render(sf::RenderTarget &target, sf::RenderStates state) const {
    for(std::vector<sf::Drawable*>::const_reference itr : *this) {
        target.draw(*itr,state);
    }
}
