#include "Debug.hpp"

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "../Log.hpp"

void unicodeToAnsi(char* c)
{
	if(*c >= 0 && *c<=25) // minuscule
		*c+=97;
	else if(*c>=26 && *c<=36)//numbers
		*c+=22;
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
	
	mNNet = ae::Application::createEntity<NeuralNet>();
	
	mInput.setCharacterSize(14);
	mReturn.setCharacterSize(14);
	mInput.setPosition(30,400);
	mReturn.setPosition(20,200);
	mInput.setColor(sf::Color::Red);
	mReturn.setColor(sf::Color::Green);
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
  {
    mNNet->addNeuron();
    printReturn("neuron added");
  }
  else if(mCmd.find("rm neur",0,7)==0)
  {
    int id;
    sscanf(mCmd.c_str(),"rm neur %d",&id);
    mNNet->rmNeuron(id);
    printReturn("neuron removed");
  }
  else if(mCmd.compare("exit")==0 ||mCmd.compare("quit")==0)
    ae::Application::close();
    
}
void ae::Debug::printReturn(std::string str)
{
  if(mOutput.c_str(),ae::utils::getLineNb(mOutput)<mReturnMax)
    mOutput +="\n"+str;
  else
    scrollReturn(str);
  mReturn.setString(mOutput.c_str());
}
void ae::Debug::scrollReturn(std::string str)
{
  auto i = std::find(str.begin(), str.end(), '\n');
  i++;
  str.erase(str.begin(),i);
  mOutput += "\n" + str;
}
