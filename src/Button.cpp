#include "Button.hpp"

#include "Log.hpp"

ae::Button::Button()
{
  sf::Font font;
  if (!font.loadFromFile("arial.ttf"))
  {
    PRINT("Error can't open font file");
  }
  mText.setFont(font);
  mText.setString("Button");
  mText.setCharacterSize(14);
  mText.setColor(sf::Color::Red);
  mShape.setFillColor(sf::Color(100, 250, 50));
  mShape.setRadius(50);
  if (!mRenderTexture.create(500, 500))
  {
   PRINT("Error Can't create texture");
  }
  mRenderTexture.clear();
  mRenderTexture.draw(mShape);
  mRenderTexture.draw(mText);
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
 PRINT("Ok free ressource ");
}
