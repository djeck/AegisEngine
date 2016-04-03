#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Drawable.hpp"
#include "Types.hpp"

namespace ae
{
  class Button : public Drawable
  {
  public:
    static const uint64_t type = "Button"_type;
    Button();
    ~Button();
    sf::Sprite& getSprite();
  private:
    sf::RenderTexture mRenderTexture;
    sf::CircleShape mShape;
    sf::Sprite *mSprite;
  };
}
#endif // BUTTON_HPP