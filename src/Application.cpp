#include "Application.hpp"

ae::Application ae::Application::mInstance;

ae::Application::Application()
{
    mWindow = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "AegiEngine", !sf::Style::Resize || sf::Style::Close );
    if (!mFont.loadFromFile("./media/arial.ttf"))
    {
        PRINT("Error can't open font file");
    }
    PRINT("Ok is running ");
}
ae::Application::~Application()
{
    PRINT("Ok free resource");
    for(auto it = mDrawables.begin(); it!=mDrawables.end(); it++)
        (*it).reset();
    mDrawables.clear();
    for(auto it = mClockListener.begin(); it!=mClockListener.end(); it++)
        (*it).reset();
    mClockListener.clear();
    mEvent.clear();
    delete mWindow;
}
void ae::Application::run()
{
    while (mInstance.mWindow->isOpen())
    {
        sf::Event event;
        while (mInstance.mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mInstance.mWindow->close();
            else if(event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    mInstance.mWindow->close();
                }
            }
            for(auto it = mInstance.mEvent.begin(); it!=mInstance.mEvent.end(); it++)
                if((*it).first == event.type && (*it).second(event))
                    break;
        }
        mInstance.mWindow->clear();
        for(auto it = mInstance.mDrawables.begin(); it!=mInstance.mDrawables.end(); it++)
            mInstance.mWindow->draw(*(*it));
        mInstance.mWindow->display();
    }
}
void ae::Application::addEventHandler(sf::Event::EventType type,EventHandler arg0)
{
    mInstance.mEvent.push_back(std::pair<sf::Event::EventType,EventHandler>(type,arg0));
}
sf::Font& ae::Application::getFont()
{
    return mInstance.mFont;
}