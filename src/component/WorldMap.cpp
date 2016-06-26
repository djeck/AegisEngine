#include "WorldMap.hpp"

ae::WorldMap::WorldMap()
{
  if(!ae::ResourceManager::exist<sf::Texture>("world"))
  {
      auto ptr_map = ae::ResourceManager::handleResource<sf::Texture>("world");
      if (!ptr_map->loadFromFile("./media/world.png"))
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
	view.zoom(event.mouseWheel.delta/2.f+1.f);
	ae::Application::setView(view);
        return false;
    });
    
    ae::Application::addEventHandler(sf::Event::MouseButtonPressed, [](sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
	    sf::Vector2f worldPos = ae::Application::getWindow()->mapPixelToCoords(sf::Vector2i(event.mouseButton.x,event.mouseButton.y));
            sf::View view = ae::Application::getView();
	    view.setCenter(worldPos);
	    ae::Application::setView(view);
        }
        return false;
    });
    
}
ae::WorldMap::~WorldMap()
{

}
