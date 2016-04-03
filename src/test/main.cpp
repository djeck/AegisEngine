#include "../ResourceManager.hpp"
#include "../Button.hpp"


int main(int argc, char **argv) {
  ae::ResourceManager::EventHandler func,func2;
  func = [](sf::Event& event) {
  if (event.mouseButton.button == sf::Mouse::Right)
    {
        ae::Out::println("Test func the right button was pressed");
	PRINT("Test func the right button was pressed");
        ae::Out::println("Test func mouse x: %d",event.mouseButton.x);
        ae::Out::println("Test func mouse y: %d",event.mouseButton.y);
    }
    return false;
  };
  ae::ResourceManager::createEntity<ae::Button>();
  ae::ResourceManager::addEventHandler(sf::Event::MouseButtonPressed,func);
  ae::ResourceManager::addEventHandler(sf::Event::MouseButtonPressed,func);
  ae::ResourceManager::run();
    return 0;
}
