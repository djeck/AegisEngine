#include "../component/NeuronalNet.hpp"
#include "../component/Debug.hpp"


int main(int argc, char **argv)
{
    
    auto ptr_font = ae::ResourceManager::handleResource<sf::Font>("font");
    if (!ptr_font->loadFromFile("./media/arial.ttf"))
    {
        PRINT("Error can't open font file");
    }
    
    ae::Application::createEntity<ae::Debug>();
  
    ae::Application::run();
    return 0;
}
