#pragma once
#include <Engine3DLinux/Core/core.h>
#include <Engine3DLinux/interfaces/Camera.h>
#include <glm/glm.hpp>

namespace Engine3DLinux{
	/*
	 * @class EditorCamera3D
	 *
	 * @param origin
	 * @note Keeps track of the current cameras origin in the world.
	 *
	 * @param projection
	 * @note 
	 * 
	 *
	 *
	*/

	class ENGINE_API EditorCamera3D : public Camera {
	public:
		EditorCamera3D() = default;

	private:
		glm::vec3 origin = {0.f, 0.f, 0.f}; // @params {x, y, z}
	};
};
