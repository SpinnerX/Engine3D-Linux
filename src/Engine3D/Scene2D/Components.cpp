#include <Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <glm/glm.hpp>
#include <Engine3DLinux/Scene2D/Components.h>

namespace Engine3D{
    glm::mat4 TransformComponent::getTransform() const {
			/* glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), rotation.x, {1, 0, 0}) */
			/* 					 * glm::rotate(glm::mat4(1.0f), rotation.y, {0, 1, 0}) */
			/* 					 * glm::rotate(glm::mat4(1.0f), rotation.z, {0, 0, 1}); */
			glm::mat4 rotate = glm::toMat4(glm::quat(rotation));
			// glm::mat4 rotate = glm::mat4(glm::quat(rotation));

			return glm::translate(glm::mat4(1.0f), translation)
				   *  rotate
				   *  glm::scale(glm::mat4(1.0f), scale);
		}
};