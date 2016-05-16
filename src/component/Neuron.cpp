#include "Neuron.hpp"

#include <sstream>
#include "../Log.hpp"

int ae::Neuron::id=0;

bool ae::Neuron::collision(int xmouse, int ymouse)
{
	return (xmouse > mRect.getPosition().x && xmouse < mRect.getPosition().x + mRect.getSize().x) &&
	(ymouse > mRect.getPosition().y && ymouse < mRect.getPosition().y + mRect.getSize().y);
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
ae::Neuron::~Neuron()
{
	PRINT("Ok free ressource ");
}
void ae::Neuron::setCallBack(Callback callback)
{
	mCallback = callback;
}