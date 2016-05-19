#include "../Application.hpp"
#include "../component/Neuron.hpp"
#include "../component/Debug.hpp"


int main(int argc, char **argv)
{
    ae::Application::EventHandler func;
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
    ae::Application::createEntity<ae::Debug>();
    auto neuron = ae::Application::createEntity<ae::Neuron>();
    neuron->setCallBack(func2);
    PRINT("Test %s correspond to %d",TYPE(neuron),HASH(neuron));
    ae::Application::addEventHandler(sf::Event::MouseButtonPressed,func);
    ae::Application::run();
    return 0;
}
