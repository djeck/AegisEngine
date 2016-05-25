#ifndef NEURON_HPP
#define NEURON_HPP

#include "../ResourceManager.hpp"
#include "../Application.hpp"
#include "../Drawable.hpp"
#include "../Types.hpp"

namespace ae
{
	class Neuron : public Drawable
	{
	public:
		static const uint64_t type = "Neuron"_type;
		typedef std::function<void(const int&)> Callback;
		Callback callback;
		bool collision(int xmouse,int ymouse);
		Neuron(const sf::Vector2f& pos,Neuron::Callback cb);
		~Neuron();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
		  states.transform *= getTransform();
		  target.draw(mRect,states);
		  target.draw(mText,states);
		}
		void setPosition(const sf::Vector2f& pos);
		int getId();
	private:
		sf::Text mText;
		sf::RectangleShape mRect;
		int mId;
		static int id;
	};
}
#endif // NEURON_HPP