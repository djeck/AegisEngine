#ifndef TYPES_HPP
#define TYPES_HPP

#include <iostream>

#define HASH(expr) Hash(#expr,sizeof(#expr))
#define TYPE(expr) #expr

constexpr uint64_t Hash(const char *str, std::size_t sz)
{
    return sz == 0 ? 0xcbf29ce484222325 : (str[0] ^ Hash(str + 1, sz - 1)) * 0x100000001b3;
}
constexpr uint64_t operator"" _type(const char *str, std::size_t sz)
{
    return Hash(str, sz);
}

#endif // TYPES_HPP