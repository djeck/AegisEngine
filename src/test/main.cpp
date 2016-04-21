#include "../ResourceManager.hpp"
#include "../Button.hpp"


int main(int argc, char **argv)
{
    ae::ResourceManager::EventHandler func;
    ae::Button::Callback func2;
    func = [](sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
            {
                PRINT("Test func mouse x: %d, y: %d",event.mouseButton.x,event.mouseButton.y);
            }
        return false;
    };
    func2 = [](int id)
    {
        PRINT("Button %d Callback",id);
        return false;
    };
    auto button = ae::ResourceManager::createEntity<ae::Button>();
    button->setCallBack(func2);
    button = ae::ResourceManager::createEntity<ae::Button>();
    button->setCallBack(func2);
    ae::ResourceManager::addEventHandler(sf::Event::MouseButtonPressed,func);
    ae::ResourceManager::run();
    return 0;
}
