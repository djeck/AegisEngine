#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../Types.hpp"
#include "../Drawable.hpp"
#include <functional>
#include <memory>

namespace ae
{
class Window : public Drawable
{
public:
    static const uint64_t type = "Button"_type;
    Window();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
	if(mVisible)
	  for(auto it = mDrawables.begin(); it!=mDrawables.end(); it++)
            target.draw(*(*it), states);
    }
    template <typename T, typename ... Args>
    std::shared_ptr<T> createEntity(Args&& ... args);
    template <typename T>
    std::shared_ptr<T> addEntity(std::shared_ptr<T> ptr);
    ~Window();
private:
    std::vector<std::shared_ptr<Drawable>> mDrawables;
    bool mVisible;
};
template <typename T, typename ... Args>
std::shared_ptr<T> Window::createEntity(Args&& ... args)
{
    std::shared_ptr<T> ptr = std::make_shared<T>(std::forward<Args>(args)...);
    std::shared_ptr<Drawable> drawable = std::dynamic_pointer_cast<Drawable>(ptr);
    if(drawable)
      mDrawables.push_back(drawable);
    return ptr;
}

template <typename T>
std::shared_ptr<T> Window::addEntity(std::shared_ptr<T> ptr)
{
    std::shared_ptr<Drawable> drawable = std::dynamic_pointer_cast<Drawable>(ptr);
    if(drawable)
      mDrawables.push_back(drawable);
    return ptr;
}
}

#endif // WINDOW_HPP