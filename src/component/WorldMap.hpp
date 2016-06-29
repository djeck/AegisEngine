#ifndef WOLRDMAP_HPP
#define WORLDMAP_HPP

#include "../Application.hpp"
#include "../ResourceManager.hpp"
#include "../Drawable.hpp"

namespace ae
{
class WorldMap : public Drawable
{
public:
    static const uint64_t type = "WoldMap"_type;
    
    WorldMap();
    ~WorldMap();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(mSprite, states);
    }
private:
    sf::Sprite mSprite;
  
}; 
}

#endif // WORLDMAP_HPP