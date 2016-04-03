#include "../ResourceManager.hpp"
#include "../Button.hpp"


int main(int argc, char **argv) {
  ae::ResourceManager::EventHandler func,func2;
  func = [](sf::Event& event) {
  if (event.mouseButton.button == sf::Mouse::Right)
    {
        PRINT("Test func mouse x: %d, y: %d",event.mouseButton.x,event.mouseButton.y);
    }
    return false;
  };
  ae::ResourceManager::createEntity<ae::Button>();
  ae::ResourceManager::addEventHandler(sf::Event::MouseButtonPressed,func);
  ae::ResourceManager::run();
    return 0;
}
