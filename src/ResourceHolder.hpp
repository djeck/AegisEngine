#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>

#include "ResourceHBase.hpp"

namespace ae
{
  
  template <typename T>
  class ResourceHolder: public ResourceHBase
  {
  public:
    static const uint64_t resourceType = HASH(ResourceHolder<T>);
    ResourceHolder();
    ~ResourceHolder();
    
    const uint64_t getType(){return resourceType;};
    
    template <typename ... Args>
    std::shared_ptr<T> push(const std::string& str, Args&& ... args)
    {
      std::shared_ptr<T> ptr = std::make_shared<T>(std::forward<Args>(args)...);
      mMap[str]=ptr;
      return ptr;
    }
    
    std::shared_ptr<T> get(const std::string& str);
  private:
    std::map<std::string,std::shared_ptr<T>> mMap;
  };
  
  template <typename T>
  ResourceHolder<T>::ResourceHolder()
  {
  }
  
  template <typename T>
  ResourceHolder<T>::~ResourceHolder()
  {
  }
  
  template <typename T>
  std::shared_ptr< T > ResourceHolder<T>::get(const std::string& str)
  {
    return mMap[str];
  }

}

#endif
