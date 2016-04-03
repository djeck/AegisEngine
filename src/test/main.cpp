#include "../ResourceManager.hpp"
#include "../Button.hpp"


int main(int argc, char **argv) {
  ae::ResourceManager::EventHandler func,func2;
  func = [](sf::Event& event) {
  if (event.mouseButton.button == sf::Mouse::Right)
    {
        std::cout << "Test func the right button was pressed" << std::endl;
        std::cout << "Test func mouse x: " << event.mouseButton.x << std::endl;
        std::cout << "Test func mouse y: " << event.mouseButton.y << std::endl;
    }
    return true;
  };
  func2 = [](sf::Event& event) {
  if (event.mouseButton.button == sf::Mouse::Right)
    {
        std::cout << "Test func2 the right button was pressed" << std::endl;
        std::cout << "Test func2 mouse x: " << event.mouseButton.x << std::endl;
        std::cout << "Test func2 mouse y: " << event.mouseButton.y << std::endl;
    }
    return true;
  };
  ae::ResourceManager::createEntity<ae::Button>();
  ae::ResourceManager::addEventHandler(sf::Event::MouseButtonPressed,func);
  ae::ResourceManager::addEventHandler(sf::Event::MouseButtonPressed,func2);
  ae::ResourceManager::run();
    return 0;
}
