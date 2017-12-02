#include "DestructibleObject.hpp"

namespace Game {


DestructibleObject::DestructibleObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY,
                                       int width, int height) : Object(graphics, filePath, sourceX, sourceY, width,
                                                                       height) {}
}
