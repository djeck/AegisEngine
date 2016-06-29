#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "../ResourceManager.hpp"
#include "../Application.hpp"
#include "../Drawable.hpp"
#include "../Types.hpp"
#include "NeuralNet.hpp"
#include "../Utils.hpp"

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
		    target.draw(mReturn, states);
		    target.draw(mInput, states);
		}
	private:
	  void cmdHandler();
	  void printReturn(std::string str);
	  void scrollReturn(std::string str);
	  sf::Text mInput;
	  sf::Text mReturn;
	  unsigned int mReturnMax; // max return lines
	  std::string mCmd;
	  std::string mOutput;
	  std::shared_ptr<NeuralNet> mNNet;
	};
}
#endif // DEBUG_HPP