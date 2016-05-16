#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>

#  undef FunctionName
#  define PRINT(...)	ae::Out::printInfo( __PRETTY_FUNCTION__,__FILE__,__LINE__,__VA_ARGS__)

namespace ae
{
class Out
{
public:
    template<class... Args>
    static void printInfo(const char* fcn,const char* file,int line,const std::string & format, Args&&... args);
private:
	static bool contain(const std::string & ref,const std::string & format);
};

template<class... Args>
void Out::printInfo(const char* fcn,const char* file,int line,const std::string & format, Args&&... args)
{
    std::string str = "%s, %s, %d:\t\t"+format;
#ifdef __linux__
    if(contain(format,"Error"))
        printf("\033[31m");
    else if(contain(format,"Ok"))
        printf("\033[32m");
    else if(contain(format,"Test"))
        printf("\033[33m");
#endif
#pragma GCC diagnostic ignored "-Wformat-security"
    printf(str.c_str(), file, fcn, line, std::forward<Args>(args)...);
    printf("\033[m\n");
}
}

#endif // LOG_HPP
