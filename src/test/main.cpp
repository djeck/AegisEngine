#include "../ResourceManager.hpp"
#include "../Application.hpp"
#include "../component/Neuron.hpp"
#include "../component/Debug.hpp"


int main(int argc, char **argv)
{
    
    auto ptr_font = ae::ResourceManager::handleResource<sf::Font>("font");
    if (!ptr_font->loadFromFile("./media/arial.ttf"))
    {
        PRINT("Error can't open font file");
    }
    
    ae::Application::EventHandler func;
    ae::Neuron::Callback func2;
    
    auto neuron = ae::Application::createEntity<ae::Neuron>(sf::Vector2f(0,0));
    ae::Application::createEntity<ae::Debug>();
    
    func = [&neuron](sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
            {
                PRINT("Test func mouse x: %d, y: %d",event.mouseButton.x,event.mouseButton.y);
            }
        else
	       neuron->setPosition(sf::Vector2f(event.mouseButton.x,event.mouseButton.y));
        return false;
    };
    func2 = [](int id)
    {
        PRINT("Test Neuron %d Callback",id);
        return false;
    };
    
    neuron->setCallBack(func2);
    
    PRINT("Test %s correspond to %d",TYPE(neuron),HASH(neuron));
    ae::Application::addEventHandler(sf::Event::MouseButtonPressed,func);
    ae::Application::run();
    return 0;
}
