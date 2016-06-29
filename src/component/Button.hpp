#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../ResourceManager.hpp"
#include "../Application.hpp"
#include "../Drawable.hpp"
#include "../Types.hpp"

namespace ae
{
class Button : public Drawable
{
public:
    static const uint64_t type = "Button"_type;
    typedef std::function<void(const int&)> Callback;
    bool collision(int xmouse,int ymouse);
    
    Button();
    ~Button();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(mShape, states);
	target.draw(mText, states);
    }
    void setCallBack(Callback callback);
    void setPosition(const sf::Vector2f &pos);
    const sf::Vector2f& getPosition();
private:
    sf::Text mText;
    sf::RectangleShape mShape;
    Callback mCallback;
    int mId;
    static int id;
};
}
#endif // BUTTON_HPP