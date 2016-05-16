#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../ResourceManager.hpp"
#include "../Drawable.hpp"
#include "../Types.hpp"

namespace ae
{
class Button : public Drawable
{
public:
    typedef std::function<void(const int&)> Callback;
    bool collision(int xmouse,int ymouse);
    static const uint64_t type = "Button"_type;
    Button();
    ~Button();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(mShape, states);
	target.draw(mText, states);
    }
    void setCallBack(Callback callback);
private:
    sf::Text mText;
    sf::RectangleShape mShape;
    Callback mCallback;
    int mId;
    static int id;

    sf::Sprite *mSprite;
    sf::RenderTexture mRenderTexture;
};
}
#endif // BUTTON_HPP