#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

#include "ResourceHolder.hpp"
#include "Log.hpp"

namespace ae
{
  class ResourceManager
  {
  public:
    ResourceManager();
    ~ResourceManager();
    
    template <typename T,typename ... Args>
    static std::shared_ptr<T> handleResource(const std::string& str, Args&&... args); // create a RH if necessary (not exist) and put resource inside
    
    template <typename T>
    static std::shared_ptr<T> get(const std::string& str);
  private:
    static ResourceManager mInstance;
    std::vector<std::shared_ptr<ResourceHBase>> mResource;
  };
  
  template <typename T,typename ... Args>
  std::shared_ptr<T> ResourceManager::handleResource(const std::string& str, Args&&... args)
  {
    for(auto it = mInstance.mResource.begin();it != mInstance.mResource.end();it++)
    {
      std::shared_ptr<ResourceHolder<T>> ptr = std::dynamic_pointer_cast<ResourceHolder<T>>((*it));
      if(ptr)
      {
	PRINT("Ok Resource \'%s\' added to resource holder",str.c_str());
	return ptr->push(str,std::forward<Args>(args)...);
      }
    }
    std::shared_ptr<ResourceHolder<T>> ptr = std::make_shared<ResourceHolder<T>>();
    mInstance.mResource.push_back(ptr);
    PRINT("Warning Resource Holder created because of resource \'%s\'",str.c_str());
    return ptr->push(str,std::forward<Args>(args)...);
  }
  
  template <typename T>
  std::shared_ptr<T> ResourceManager::get(const std::string& str)
  {
    for(auto it = mInstance.mResource.begin();it != mInstance.mResource.end();it++)
    {
      std::shared_ptr<ResourceHolder<T>> ptr = std::dynamic_pointer_cast<ResourceHolder<T>>((*it));
      if(ptr)
      {
	std::shared_ptr< T > result = ptr->get(str);
	if(result)
	  return result;
      }
    }
    PRINT("Error Resource \'%s\' can\'t be found",str.c_str());
    return nullptr;
  }
}
#endif
