#include "Button.hpp"

#include "../Log.hpp"

int ae::Button::id=0;

bool ae::Button::collision(int xmouse, int ymouse)
{
    return (xmouse > mSprite->getPosition().x + mShape.getPosition().x && xmouse < mSprite->getPosition().x + mShape.getPosition().x + mShape.getSize().x) &&
           (ymouse > mSprite->getPosition().y + mShape.getPosition().y && ymouse < mSprite->getPosition().y + mShape.getPosition().y + mShape.getSize().y);
}

ae::Button::Button()
{
    mId=id;
    id++;
    mText.setFont(ae::ResourceManager::getFont());
    mText.setString("Button");
    mText.setCharacterSize(14);
    mText.setColor(sf::Color::Red);
    mShape.setFillColor(sf::Color(100, 250, 50));
    mShape.setSize(sf::Vector2f(50.f,50.f));
    mShape.setPosition(50.f,50.f);
    if (!mRenderTexture.create(500, 500))
    {
        PRINT("Error Can't create texture");
    }
    mRenderTexture.clear();
    mRenderTexture.draw(mShape);
    //mRenderTexture.draw(mText);
    mRenderTexture.display();
    mSprite = new sf::Sprite(mRenderTexture.getTexture());
    mSprite->setPosition(150,150);
    ae::ResourceManager::addEventHandler(sf::Event::MouseButtonPressed, [this](sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if(collision(event.mouseButton.x,event.mouseButton.y) && mCallback)
                mCallback(mId);
        }
        return false;
    });
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
void ae::Button::setCallBack(Callback callback)
{
    mCallback = callback;
}

