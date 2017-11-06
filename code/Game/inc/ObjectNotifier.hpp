#pragma once

namespace Game {
class Object;

class ObjectNotifier {
public:
    virtual void addObject(std::unique_ptr<Object> object) = 0;
    virtual ~ObjectNotifier() = default;
};

}