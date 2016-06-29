#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <SFML/Graphics.hpp>

const sf::Vector2u& operator/(const sf::Vector2u& a, unsigned int b);
const bool operator>(const sf::Vector2i& a, int b);
const sf::Vector2i operator-(const sf::Vector2i& a, const sf::Vector2u& b);
const bool operator>(const sf::Vector2i& a, const sf::Vector2u& b);
const sf::Vector2i& unit(const sf::Vector2i& u);

namespace ae
{
  namespace utils
  {
    unsigned int getLineNb(const std::string& str);
  }
}

#endif
