#ifndef RESOURCEHBASE_HPP
#define RESOURCEHBASE_HPP

#include "Types.hpp"

namespace ae
{
  class ResourceHBase
  {
  public:
    ResourceHBase();
    virtual const uint64_t getType()=0;
    ~ResourceHBase();
  private:
  };
}

#endif
