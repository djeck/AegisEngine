#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

namespace ae
{
class Drawable : public Entity
{
public:
    static const uint64_t type = "Drawable"_type;
    virtual sf::Sprite& getSprite() = 0;
protected:
};
}
#endif // DRAWABLE_HPP