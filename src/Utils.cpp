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
