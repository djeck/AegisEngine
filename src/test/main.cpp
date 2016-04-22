#include "../ResourceManager.hpp"
#include "../component/Neuron.hpp"
#include "../component/Debug.hpp"


int main(int argc, char **argv)
{
    ae::ResourceManager::EventHandler func;
    ae::Neuron::Callback func2;
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
        PRINT("Test Neuron %d Callback",id);
        return false;
    };
    ae::ResourceManager::createEntity<ae::Debug>();
    auto neuron = ae::ResourceManager::createEntity<ae::Neuron>();
    neuron->setCallBack(func2);
    ae::ResourceManager::addEventHandler(sf::Event::MouseButtonPressed,func);
    ae::ResourceManager::run();
    return 0;
}
