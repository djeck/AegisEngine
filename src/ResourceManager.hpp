#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <iostream>
#include <map>
#include <functional>
#include <memory>

#include "ClockListener.hpp"
#include "Drawable.hpp"
#include "Log.hpp"

namespace ae
{
class ResourceManager
{
public:
    typedef std::function<bool(sf::Event&)> EventHandler;
    ResourceManager();
    ~ResourceManager();

    static void run();

    static void addEventHandler(sf::Event::EventType type,EventHandler arg0);

    template <typename T, typename ... Args>
    static std::shared_ptr<T> createEntity(Args&& ... args);
    template <typename T>
    static std::shared_ptr<T> addEntity(std::shared_ptr<T> ptr);
    static sf::Font& getFont();
private:
    static ResourceManager mInstance;
    sf::Font mFont;

    std::vector<std::pair<sf::Event::EventType,EventHandler>> mEvent;

    std::vector<std::shared_ptr<Drawable>> mDrawables;
    std::vector<std::shared_ptr<ClockListener>> mClockListener;

    sf::RenderWindow* mWindow;
};

template <typename T, typename ... Args>
std::shared_ptr<T> ResourceManager::createEntity(Args&& ... args)
{
    std::shared_ptr<T> ptr = std::make_shared<T>(std::forward<Args>(args)...);
    std::shared_ptr<Drawable> drawable = std::dynamic_pointer_cast<Drawable>(ptr);
    std::shared_ptr<ClockListener> clockListener = std::dynamic_pointer_cast<ClockListener>(ptr);
    if(drawable)
    {
        PRINT("Ok Drawable added");
        mInstance.mDrawables.push_back(drawable);
    }
    if(clockListener)
    {
        PRINT("Ok ClockListener added");
        mInstance.mClockListener.push_back(clockListener);
    }
    return ptr;
}

template <typename T>
std::shared_ptr<T> ResourceManager::addEntity(std::shared_ptr<T> ptr)
{
    std::shared_ptr<Drawable> drawable = std::dynamic_pointer_cast<Drawable>(ptr);
    std::shared_ptr<ClockListener> clockListener = std::dynamic_pointer_cast<ClockListener>(ptr);
    if(drawable)
        mInstance.mDrawables.push_back(drawable);
    if(clockListener)
        mInstance.mClockListener.push_back(clockListener);
    return ptr;
}
}
#endif // RESOURCEMANAGER_HPP
