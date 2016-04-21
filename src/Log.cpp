#include "Log.hpp"

bool ae::Out::contain(const char* ref,const char* format)
{
    if(strlen(ref)<strlen(format))
        return false;
    for(size_t i=0; i<strlen(format); i++)
        if(ref[i]!=format[i])
            return false;
    return true;
}