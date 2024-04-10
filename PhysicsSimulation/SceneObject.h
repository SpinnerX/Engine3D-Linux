#pragma once
#include <glm/glm.hpp>
#include <Engine3DLinux/Core/Timestep.h>
#include <Engine3DLinux/interfaces/Texture.h>
#include <Engine3DLinux/interfaces/Shader.h>

/**
 * 
 * @name SceneObject
 * @note Since this represents an object in our WorldView
 * @note Using this object to interact with other objects in the world.
 * 
 * parameters
 * @note Scene object may attach either a shader color or a texture
 * @note Contains position, and gravitational pulse threshold
 * @note For physics parameters, we will have acceleration
 * @note Using this object to simulate Circular motion in 2D space.
*/

class SceneObject{
public:
    SceneObject(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);

    void load(const std::string& path);

    void onUpdate(Engine3DLinux::Timestep ts);

    void onUIRender();

    void setPosition(const glm::vec2& pos) { position = pos; }

    const glm::vec2& getPosition() const { return position; }

    const glm::vec2& getSize() const { return size; }

    const glm::vec4& getColor() const { return color; }

    bool inBounds(const glm::vec2& position);

private:
    glm::vec2 position;
    glm::vec2 size;
    glm::vec4 color;
    float time = 0.f;
    glm::vec2 velocity = {5.f, 5.f};
    float gravityThreshold = 0.8f;
    Engine3DLinux::Ref<Engine3DLinux::Texture2D> texture;
    Engine3DLinux::Ref<Engine3DLinux::Shader> shader; //! @note Possibly having this object represent a shape!
};