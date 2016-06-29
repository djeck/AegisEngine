#include "WorldMap.hpp"
#include "../Utils.hpp"

ae::WorldMap::WorldMap()
{
  if(!ae::ResourceManager::exist<sf::Texture>("world"))
  {
      auto ptr_map = ae::ResourceManager::handleResource<sf::Texture>("world");
      if (!ptr_map->loadFromFile("./media/world_2cb.png"))
      {
	  PRINT("Error can't open world map file");
      }
  }
  mSprite.setTexture(*ae::ResourceManager::get<sf::Texture>("world"));
  sf::View view1(sf::FloatRect(0, 0, 3100, 1600));
  ae::Application::setView(view1);
  
  ae::Application::addEventHandler(sf::Event::Resized, [](sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
	    PRINT("Test Resized");
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
	    ae::Application::setView(sf::View(visibleArea));
        }
        return false;
    });
    
    ae::Application::addEventHandler(sf::Event::MouseWheelMoved, [](sf::Event& event)
    {
	sf::View view = ae::Application::getView();
	view.zoom(event.mouseWheel.delta/4.f+1.f);
	ae::Application::setView(view);
        return false;
    });
    
    ae::Application::addEventHandler(sf::Event::MouseButtonPressed, [](sf::Event& event)
    {
      sf::Vector2f worldPos = ae::Application::getWindow()->mapPixelToCoords(sf::Vector2i(event.mouseButton.x,event.mouseButton.y));
        if (event.mouseButton.button == sf::Mouse::Left)
        {
        }
        else
	{
	  PRINT("Test mouse at : %.2f-%.2f",worldPos.x,worldPos.y);
	}
        return false;
    });

    ae::Application::addClockCallBack([]()
    {
        sf::Vector2i pos = sf::Mouse::getPosition(*ae::Application::getWindow());
	sf::Vector2u center = ae::Application::getWindow()->getSize()/2;
	
	if(pos-center > ae::Application::getWindow()->getSize().y/4)
	{
	  sf::View view = ae::Application::getView();
	  view.move((pos-center).x/150.f,(pos-center).y/150.f);
	  ae::Application::setView(view);
	}
    });
    
    
}
ae::WorldMap::~WorldMap()
{

}
