#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "../ResourceManager.hpp"
#include "../Application.hpp"
#include "../Drawable.hpp"
#include "../Types.hpp"

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
	};
}
#endif // DEBUG_HPP