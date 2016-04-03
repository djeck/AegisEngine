#include "ResourceManager.hpp"

ae::ResourceManager ae::ResourceManager::mInstance;

ae::ResourceManager::ResourceManager()
{
  mWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "Aegis Engine");
  PRINT("Ok is running");
}
ae::ResourceManager::~ResourceManager()
{
  PRINT("Ok free resource");
  for(auto it = mDrawables.begin();it!=mDrawables.end();it++)
    (*it).reset();
  mDrawables.clear();
  for(auto it = mClockListener.begin();it!=mClockListener.end();it++)
    (*it).reset();
  mClockListener.clear();
  mEvent.clear();
  delete mWindow;
}
void ae::ResourceManager::run()
{
    while (mInstance.mWindow->isOpen())
    {
        sf::Event event;
        while (mInstance.mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mInstance.mWindow->close();
	    for(auto it = mInstance.mEvent.begin();it!=mInstance.mEvent.end();it++)
	      if((*it).first == event.type && (*it).second(event))
	       break;
        }
        mInstance.mWindow->clear();
	for(auto it = mInstance.mDrawables.begin();it!=mInstance.mDrawables.end();it++)
	  mInstance.mWindow->draw((*it)->getSprite());
        mInstance.mWindow->display();
    }
}
void ae::ResourceManager::addEventHandler(sf::Event::EventType type,EventHandler arg0)
{
  mInstance.mEvent.push_back(std::pair<sf::Event::EventType,EventHandler>(type,arg0));
}
