#include <Engine3DLinux/Scene/Entity.h>


namespace Engine3DLinux{

	Entity::Entity(entt::entity handle, Scene* scene) : _entityHandler(handle), _scene(scene) {}
};
