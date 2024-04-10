#include "SceneObject.h"
#include "interfaces/Texture.h"

SceneObject::SceneObject(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color) : position(position), size(size), color(color){}

void SceneObject::load(const std::string& path){
    // texture = Engine3DLinux::Texture2D::Create("assets/textures/GroundTexture.png");
}

void SceneObject::onUpdate(Engine3DLinux::Timestep ts){
    time += ts;

    velocity.y -= gravityThreshold;

    velocity.y = glm::clamp(velocity.y, -20.0f, 20.0f);
	position += velocity * (float)ts;
}

void SceneObject::onUIRender(){}