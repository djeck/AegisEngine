#include "Log.hpp"

bool ae::Out::contain(const std::string & ref,const std::string & format)
{
    if(ref.length()<format.length())
        return false;
    for(size_t i=0; i<format.length(); i++)
        if(ref.at(i)!=format.at(i))
            return false;
    return true;
}