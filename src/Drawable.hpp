#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Log.hpp"

namespace ae
{
class Drawable : public Entity, public sf::Drawable, public sf::Transformable
{
public:
    static const uint64_t type = "Drawable"_type;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states){};
protected:
};
}
#endif // DRAWABLE_HPP