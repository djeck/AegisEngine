#include "Button.hpp"

#include "Log.hpp"

ae::Button::Button()
{
  mShape.setFillColor(sf::Color(100, 250, 50));
  mShape.setRadius(50);
  if (!mRenderTexture.create(500, 500))
  {
    ae::Out::println("Error Button::Button: can't create texture");
  }
  mRenderTexture.clear();
  mRenderTexture.draw(mShape);
  mRenderTexture.display();
  mSprite = new sf::Sprite(mRenderTexture.getTexture());
}
sf::Sprite& ae::Button::getSprite()
{
  return *mSprite;
}
ae::Button::~Button()
{
  delete mSprite;
  ae::Out::println("Ok Button::~Button free ressource ");
}
