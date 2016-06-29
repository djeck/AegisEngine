#include "../component/NeuralNet.hpp"
#include "../component/Button.hpp"
#include "../component/Debug.hpp"
#include "../component/WorldMap.hpp"


int main(int argc, char **argv)
{
    
    auto ptr_font = ae::ResourceManager::handleResource<sf::Font>("font");
    if (!ptr_font->loadFromFile("./media/arial.ttf"))
    {
        PRINT("Error can't open font file");
    }
    
    ae::Application::createEntity<ae::WorldMap>();
    //ae::Application::createEntity<ae::Debug>();
    ae::Application::createEntity<ae::Button>()->setCallBack([](const int& id)
    {
	PRINT("Test Button %d clicked",id);
    });
  
    ae::Application::run();
    return 0;
}
