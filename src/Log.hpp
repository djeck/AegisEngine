#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>

namespace ae
{
 class Out
 {
 public:
   template<class... Args>
   static void println(const char* format, Args&&... args);
 private:
   static bool contain(const char* ref,const char* format);
 };
 
 template<class... Args>
  void Out::println(const char* format, Args&&... args)
  {
    if(contain(format,"Error"))
      printf("\033[31m");
    else if(contain(format,"Ok"))
      printf("\033[32m");
    else if(contain(format,"Test"))
      printf("\033[33m");
    #pragma GCC diagnostic ignored "-Wformat-security"
    printf(format, std::forward<Args>(args)...);
    printf("\033[m\n");
  }
}

#endif // LOG_HPP