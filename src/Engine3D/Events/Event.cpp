#include <Engine3DLinux/Events/Event.h>


namespace Engine3D{
    bool Event::isEventCurrentlyHandled() const {
        return isHandled;
    }
};