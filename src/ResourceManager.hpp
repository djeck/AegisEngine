#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <SFML/Graphics.hpp>

#include "ResourceHolder.hpp"

namespace ae
{
  class ResourceManager
  {
  public:
    ResourceManager();
    ~ResourceManager();
    
    template <typename T>
    void registerRH(ResourceHolder<T> );
    
    template <typename T>
    void addRH(); // create
    
    template <typename T,typename ... Args>
    void handleResource( Args&&... args); // create a RH if necessary (not exist) and put resource inside
  private:
    static ResourceManager mInstance;
    std::map<const std::string,const uint64_t> mId;
    std::map<const uint64_t, ResourceHBase> mResource;
  };
}
#endif
