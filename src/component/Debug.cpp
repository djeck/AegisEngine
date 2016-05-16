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
	mText.setCharacterSize(14);
	mText.setPosition(0,0);
	mText.setColor(sf::Color::Red);
	this->setPosition(50,400);
	
	ae::ResourceManager::addEventHandler(sf::Event::KeyPressed, [this](sf::Event& event)
	{
		if(event.key.code== sf::Keyboard::Return)
		{
		  cmdHandler();
		  mCmd.clear();
		}
		else if(event.key.code== sf::Keyboard::BackSpace && mCmd.size()>0)
		{
		  mCmd.pop_back();
		  mText.setString(mCmd.c_str());
		}
		else if(event.key.code== sf::Keyboard::Tab)
		{
		}
		else if(event.key.code== sf::Keyboard::Delete && mCmd.size()>0)
		{
		  mCmd.pop_back();
		  mText.setString(mCmd.c_str());
		}
		else if (event.text.unicode < 128)
		{
			char c =(char)event.text.unicode;
			unicodeToAnsi(&c);
			if(alfaNumeric(c))
			{
				mCmd.push_back(c);
				mText.setString(mCmd.c_str());
			}
		}
		return false;
	});
}
ae::Debug::~Debug()
{
}
void ae::Debug::cmdHandler()
{

}
