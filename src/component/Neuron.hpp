#ifndef NEURON_HPP
#define NEURON_HPP

#include "../ResourceManager.hpp"
#include "../Drawable.hpp"
#include "../Types.hpp"

namespace ae
{
	class Neuron : public Drawable
	{
	public:
		static const uint64_t type = "Neuron"_type;
		
		typedef std::function<void(const int&)> Callback;
		bool collision(int xmouse,int ymouse);
		Neuron();
		~Neuron();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
		  states.transform *= getTransform();

		  target.draw(mRect,states);
		  target.draw(mText,states);
		}
		void setCallBack(Callback callback);
	private:
		sf::Text mText;
		sf::RectangleShape mRect;
		Callback mCallback;
		int mId;
		static int id;
	};
}
#endif // NEURON_HPP