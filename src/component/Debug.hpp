#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "../ResourceManager.hpp"
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
		sf::Sprite& getSprite();
	private:
		sf::Text mText;
		std::string mCmd;
		
		sf::Sprite *mSprite;
		sf::RenderTexture mRenderTexture;
	};
}
#endif // DEBUG_HPP