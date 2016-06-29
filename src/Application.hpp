#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#define WIN_W 1000
#define WIN_H  600

#include <iostream>
#include <map>
#include <functional>
#include <memory>

#include "ClockListener.hpp"
#include "Drawable.hpp"
#include "Log.hpp"

namespace ae
{
class Application
{
public:
    typedef std::function<bool(sf::Event&)> EventHandler;
    typedef std::function<void()> ClockCallBack;
    Application();
    ~Application();

    static void run();

    static void addEventHandler(sf::Event::EventType type,EventHandler arg0);
    
    static void addClockCallBack(ClockCallBack arg0);

    template <typename T, typename ... Args>
    static std::shared_ptr<T> createEntity(Args&& ... args);
    template <typename T>
    static std::shared_ptr<T> addEntity(std::shared_ptr<T> ptr);
    static void close();
    static void setView(const sf::View& view);
    static const sf::View& getView();
    static sf::RenderWindow* getWindow();
private:
    static Application mInstance;

    std::vector<std::pair<sf::Event::EventType,EventHandler>> mEvent;
    std::vector<ClockCallBack> mClock;

    std::vector<std::shared_ptr<Drawable>> mDrawables;
    std::vector<std::shared_ptr<ClockListener>> mClockListener;
    
    bool mClose;

    sf::RenderWindow* mWindow;
};

template <typename T, typename ... Args>
std::shared_ptr<T> Application::createEntity(Args&& ... args)
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
std::shared_ptr<T> Application::addEntity(std::shared_ptr<T> ptr)
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
#endif // APPLICATION_HPP
