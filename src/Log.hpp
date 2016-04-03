#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>

#  undef FunctionName
#  define PRINT(...)	ae::Out::printInfo(__VA_ARGS__, __PRETTY_FUNCTION__,__FILE__,__LINE__)

namespace ae
{
 class Out
 {
 public:
   template<class... Args>
   static void println(const char* format, Args&&... args);
   template<class... Args>
   static void printInfo(const char* format, Args&&... args,const char* fnc,const char* file,const int line);
 private:
   static bool contain(const char* ref,const char* format);
 };
 
 template<class... Args>
  void Out::println(const char* format, Args&&... args)
  {
#ifdef __linux__
    if(contain(format,"Error"))
      printf("\033[31m");
    else if(contain(format,"Ok"))
      printf("\033[32m");
    else if(contain(format,"Test"))
      printf("\033[33m");
#endif
    #pragma GCC diagnostic ignored "-Wformat-security"
    printf(format, std::forward<Args>(args)...);
    printf("\033[m\n");
  }
  template<class... Args>
   void Out::printInfo(const char* format, Args&&... args,const char* fnc,const char* file,const int line)
   {
#ifdef __linux__
    if(contain(format,"Error"))
      printf("\033[31m");
    else if(contain(format,"Ok"))
      printf("\033[32m");
    else if(contain(format,"Test"))
      printf("\033[33m");
#endif
    #pragma GCC diagnostic ignored "-Wformat-security"
    printf("%s: %s: %d:  ",file,fnc,line);
    printf(format, std::forward<Args>(args)...);
    printf("\033[m\n");
   }
}

#endif // LOG_HPP
