#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "../ResourceManager.hpp"
#include "../Application.hpp"
#include "../Drawable.hpp"
#include "../Types.hpp"
#include "NeuronalNet.hpp"

namespace ae
{
	class Debug : public Drawable
	{
	public:
		static const uint64_t type = "Debug"_type;
		
		Debug();
		~Debug();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
		    states.transform *= getTransform();
		    target.draw(mText, states);
		}
	private:
	  void cmdHandler();
	  sf::Text mText;
	  std::string mCmd;
	  std::shared_ptr<NeuronalNet> mNNet;
	};
}
#endif // DEBUG_HPP