#include "Utils.hpp"

#include <iostream>

unsigned int ae::utils::getLineNb(const std::string& str)
{
int i=0;
for(auto it = str.begin(); it != str.end(); it++)
{
  i += ((*it) == '\n' || (*it) == '\0') ? 1 : 0;
}
return i;
}
const sf::Vector2u& operator/(const sf::Vector2u& a, unsigned int b)
{
  return sf::Vector2u(a.x/b,a.y/b);
}
const bool operator>(const sf::Vector2i& a, int b)
{
  return abs(a.x) > b || abs(a.y) > b;
}
const sf::Vector2i operator-(const sf::Vector2i& a, const sf::Vector2u& b)
{
  return sf::Vector2i(a.x-b.x,a.y-b.y);
}
const bool operator>(const sf::Vector2i& a, const sf::Vector2u& b)
{
  return abs(a.x) > b.x || abs(a.y) > b.y;
}
const sf::Vector2i& unit(const sf::Vector2i& u)
{
  sf::Vector2i result;
  result.x = (u.x == 0) ? 0 : u.x / abs(u.x);
  result.y = (u.y == 0) ? 0 : u.y / abs(u.y);
  return result;
}
