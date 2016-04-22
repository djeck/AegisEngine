#include "Debug.hpp"

#include <sstream>
#include "../Log.hpp"

void unicodeToAnsi(char* c)
{
	if(*c >= 0 && *c<=26) // minuscule
		*c+=97;
	else if(*c >= 75 && *c<=84) // numerique
		*c-=27;
	else if(*c==57) // space
		*c-=25;
	else if(*c==68) // minus
		*c-=23;
	else if(*c==50)//point
		*c-=4;
}
bool alfaNumeric(char c)
{
	bool min=false,maj=false,num=false,other=false;
	if(c>='a' && c<='z')
		min=true;
	else if(c>='A' && c<='Z')
		maj=true;
	else if(c>='0' && c<='9')
		num=true;
	else if(c=='-' || c=='+' || c==' '|| c=='.')
		other=true;
	return min||maj||num||other;
}

ae::Debug::Debug()
{

	mText.setFont(ae::ResourceManager::getFont());
	mText.setString(mCmd.c_str());
	mText.setCharacterSize(14);
	mText.setColor(sf::Color::Red);

	if (!mRenderTexture.create(500, 500))
	{
		PRINT("Error Can't create texture");
	}
	mRenderTexture.clear();
	mRenderTexture.draw(mText);
	mRenderTexture.display();
	mSprite = new sf::Sprite(mRenderTexture.getTexture());
	mSprite->setPosition(150,400);
	ae::ResourceManager::addEventHandler(sf::Event::KeyPressed, [this](sf::Event& event)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if(event->key.code== sf::Keyboard::Return)
			{
			}
			else if(event->key.code== sf::Keyboard::BackSpace)
			{
			}
			else if(event->key.code== sf::Keyboard::Tab)
			{
			}
			else if(event->key.code== sf::Keyboard::Delete)
			{
			}
			else if (event->text.unicode < 128)
			{
				char c =(char)event->text.unicode;
				//std::cout<<"keyboard: "<<event->text.unicode<<std::endl;
				unicodeToAnsi(&c);
				if(alfaNumeric(c))
				{
					mCmd<<c;
					mText.setString(mCmd.c_str());
					mRenderTexture.clear();
					mRenderTexture.draw(mText);
					mRenderTexture.display();
				}
			}
			return false;
		}
		return false;
	});
}
sf::Sprite& ae::Debug::getSprite()
{
	return *mSprite;
}
ae::Debug::~Debug()
{
	delete mSprite;
}
