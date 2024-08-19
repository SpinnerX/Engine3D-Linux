#include "SceneObject.h"
#include "interfaces/Texture.h"

SceneObject::SceneObject(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color) : position(position), originalPosition(position), size(size), color(color){}

void SceneObject::load(const std::string& path){
    texture = Engine3DLinux::Texture2D::Create("assets/textures/GroundTexture.png");
}

void SceneObject::onUpdate(Engine3DLinux::Timestep ts){
    time += ts;

    velocity.y -= gravityThreshold;

    //! @note clamp returns the value of x constrained to the range minVal to maxVal
    velocity.y = glm::clamp(velocity.y, -20.0f, 20.0f);
	position += velocity * (float)ts;
}

void SceneObject::onUIRender(){
}

bool SceneObject::inBoxBounds(SceneObject& object){
    glm::vec2 pos1 = object.getPosition(); // Checking overlapping with different scene object
    glm::vec2 pos2 = this->getPosition(); // Current object
    
    auto& isOverlapping = glm::max(pos1, pos2);

    if(!isOverlapping) {
        coreLogInfo("Collision, meaning the boxes has hit!");
        return true;
    }

    return false;
}

bool SceneObject::inCircleBounds(SceneObject& object){
    
    return false;
}