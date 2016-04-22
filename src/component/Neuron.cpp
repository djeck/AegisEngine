#include "Neuron.hpp"

#include <sstream>
#include "../Log.hpp"

int ae::Neuron::id=0;

bool ae::Neuron::collision(int xmouse, int ymouse)
{
	return (xmouse > mSprite->getPosition().x + mRect.getPosition().x && xmouse < mSprite->getPosition().x + mRect.getPosition().x + mRect.getSize().x) &&
	(ymouse > mSprite->getPosition().y + mRect.getPosition().y && ymouse < mSprite->getPosition().y + mRect.getPosition().y + mRect.getSize().y);
}

ae::Neuron::Neuron()
{
	std::stringstream ss;
	mId=id;
	id++;
	ss<<"Neuron "<<id<<"\n test";
	mText.setFont(ae::ResourceManager::getFont());
	mText.setString(ss.str().c_str());
	mText.setCharacterSize(14);
	mText.setColor(sf::Color::Red);
	mRect.setFillColor(sf::Color(100, 250, 50));
	mRect.setSize(sf::Vector2f(50.f,50.f));
	mRect.setPosition(50.f,50.f);
	if (!mRenderTexture.create(500, 500))
	{
		PRINT("Error Can't create texture");
	}
	mRenderTexture.clear();
	mRenderTexture.draw(mRect);
	mRenderTexture.draw(mText);
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
sf::Sprite& ae::Neuron::getSprite()
{
	return *mSprite;
}
ae::Neuron::~Neuron()
{
	delete mSprite;
	PRINT("Ok free ressource ");
}
void ae::Neuron::setCallBack(Callback callback)
{
	mCallback = callback;
}
