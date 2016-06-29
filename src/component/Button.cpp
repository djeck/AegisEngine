#include "Button.hpp"

#include "../Log.hpp"

int ae::Button::id=0;

bool ae::Button::collision(int xmouse, int ymouse)
{
    return (xmouse > mShape.getPosition().x && xmouse < mShape.getPosition().x + mShape.getSize().x) &&
           (ymouse > mShape.getPosition().y && ymouse < mShape.getPosition().y + mShape.getSize().y);
}

ae::Button::Button()
{
    mId=id;
    id++;
    mText.setFont(*ae::ResourceManager::get<sf::Font>("font"));
    mText.setString("Button");
    mText.setCharacterSize(14);
    mText.setColor(sf::Color::Red);
    mText.setPosition(sf::Vector2f(50.f,50.f));
    mShape.setFillColor(sf::Color(100, 250, 50));
    mShape.setSize(sf::Vector2f(50.f,50.f));
    mShape.setPosition(50.f,50.f);
    
    ae::Application::addEventHandler(sf::Event::MouseButtonPressed, [this](sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
	    sf::Vector2f worldPos = ae::Application::getWindow()->mapPixelToCoords(sf::Vector2i(event.mouseButton.x,event.mouseButton.y));
            if(collision(worldPos.x,worldPos.y) && mCallback)
                mCallback(mId);
        }
        return false;
    });
}
ae::Button::~Button()
{
    PRINT("Ok free Button ressource ");
}
void ae::Button::setCallBack(Callback callback)
{
    mCallback = callback;
}
const sf::Vector2f& ae::Button::getPosition()
{
  return mShape.getPosition();
}
void ae::Button::setPosition(const sf::Vector2f& pos)
{
  mText.setPosition(pos);
  mShape.setPosition(pos);
}
