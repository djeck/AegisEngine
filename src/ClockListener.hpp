#ifndef CLOCKLISTENER_HPP
#define CLOCKLISTENER_HPP

#include "Entity.hpp"

namespace ae
{
class ClockListener : public Entity
{
public:
    static const uint64_t type = "ClockListener"_type;
protected:
};
}
#endif // CLOCKLISTENER_HPP