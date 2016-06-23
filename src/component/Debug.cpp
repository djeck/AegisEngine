#include "Debug.hpp"

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
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

	mInput.setFont(*ae::ResourceManager::get<sf::Font>("font"));
	mReturn.setFont(*ae::ResourceManager::get<sf::Font>("font"));
	mReturnMax=5;
	
	mNNet = ae::Application::createEntity<NeuronalNet>();
	
	mInput.setCharacterSize(14);
	mReturn.setCharacterSize(14);
	mInput.setPosition(30,400);
	mReturn.setPosition(20,200);
	mInput.setColor(sf::Color::Red);
	mInput.setColor(sf::Color::Green);
	this->setPosition(50,400);
	
	ae::Application::addEventHandler(sf::Event::KeyPressed, [this](sf::Event& event)
	{
		if(event.key.code== sf::Keyboard::Return)
		{
		  cmdHandler();
		  mCmd.clear();
		  mInput.setString(mCmd.c_str());
		}
		else if(event.key.code== sf::Keyboard::BackSpace && mCmd.size()>0)
		{
		  mCmd.pop_back();
		  mInput.setString(mCmd.c_str());
		}
		else if(event.key.code== sf::Keyboard::Tab)
		{
		}
		else if(event.key.code== sf::Keyboard::Delete && mCmd.size()>0)
		{
		  mCmd.pop_back();
		  mInput.setString(mCmd.c_str());
		}
		else if (event.text.unicode < 128)
		{
			char c =(char)event.text.unicode;
			unicodeToAnsi(&c);
			if(alfaNumeric(c))
			{
				mCmd.push_back(c);
				mInput.setString(mCmd.c_str());
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
  if(mCmd.compare("add neur")==0)
    mNNet->addNeuron();
  else if(mCmd.find("rm neur",0,7)==0)
  {
    PRINT("Test %s",mCmd.c_str());
    int id;
    PRINT("rm neur %d",&id);
    mNNet->rmNeuron(id);
  }
  else if(mCmd.compare("exit")==0 ||mCmd.compare("quit")==0)
    ae::Application::close();
}
