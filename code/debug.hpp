#pragma once

#include <cstring>

constexpr bool __debug = true;

#define __FILENAME__ (std::strrchr(__FILE__, '/') ? std::strrchr(__FILE__, '/') + 1 : __FILE__)
#define __PREFIX__ (std::string(__FILENAME__) + std::string(":") \
                    + std::to_string(__LINE__) + std::string(": "))

#define LOG if(__debug) std::cout << __PREFIX__
#define ERROR std::cerr << (__debug ? __PREFIX__ : "" )