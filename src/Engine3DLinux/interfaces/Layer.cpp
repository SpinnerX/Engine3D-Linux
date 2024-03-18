#include <Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>
#include <Engine3DLinux/interfaces/Layer.h>

namespace Engine3DLinux{
    Layer::Layer(const std::string& name) : _debugName(name){}

    Layer::~Layer(){}
};
