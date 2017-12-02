#pragma once

#include "Tank.hpp"

namespace Game {
class Object;

class ObjectOwner {
public:
    virtual void addObject(std::unique_ptr<Object>&& object) = 0;
    virtual const std::list<std::unique_ptr<Object>>& getObjects() = 0;
    virtual const std::list<std::unique_ptr<Tank>>& getTanks() = 0;
    virtual ~ObjectOwner() = default;
};

}