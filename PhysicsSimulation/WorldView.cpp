#include "WorldView.h"
#include "Events/InputPoll.h"
#include "Events/KeyCodes.h"
#include "interfaces/Texture.h"
#include <Engine3DLinux/Renderer2D/Renderer.h>
#include <Engine3DLinux/Renderer2D/Renderer2D.h>
#include <glm/gtc/matrix_transform.hpp>

namespace Utils{
    static bool PointInTri(const glm::vec2& p, glm::vec2& p0, const glm::vec2& p1, const glm::vec2& p2){
        float s = p0.y * p2.x - p0.x * p2.y + (p2.y - p0.y) * p.x + (p0.x - p2.x) * p.y;
        float t = p0.x * p1.y - p0.y * p1.x + (p0.y - p1.y) * p.x + (p1.x - p0.x) * p.y;

        if ((s < 0) != (t < 0))
            return false;

        float A = -p1.y * p2.x + p0.y * (p2.x - p1.x) + p0.x * (p1.y - p2.y) + p1.x * p2.y;

        return A < 0 ?
            (s <= 0 && s + t >= A) :
            (s >= 0 && s + t <= A);
    }
};

WorldView::WorldView() : object({0, 0}, {1, 1}, {0.8f, 0.2f, 0.3f, 1.0f}), floorPlane({0, -34.0f}, {50.f, 50.f}, {1.f, 1.f, 1.f, 1.f}){
    plane = Engine3DLinux::Shader::CreateShader("assets/shaders/flatShader.glsl");
    // triangle.l1.position = {0, 0 * 10.f};
    // triangle.l2.position = {1, 1 * 10.f};
}

void WorldView::onEvent(Engine3DLinux::Event& event){
    if(Engine3DLinux::InputPoll::isKeyPressed(ENGINE_KEY_SPACE)){
        object.setPosition({0.f, 0.f});
    }
}

void WorldView::onUpdate(Engine3DLinux::Timestep ts){
    object.onUpdate(ts);
}

/**
 * 
 * drawRotatedQuad - used if we want to render a rotated object
 * drawQuad - used for rendering the object without rotation
 * 
*/
 
void WorldView::submit(){
    // Engine3DLinux::Renderer2D::drawQuad({0.0f, 0.0f}, {5.f, 5.f}, {0.8, 0.2f, 0.3f, 1.0f}); // @note Rendering a red square
    // Engine3DLinux::Renderer2D::drawQuad({0.f, 0.f}, {1.f, 1.f}, plane);
    Engine3DLinux::Renderer2D::drawQuad(object.getPosition(), object.getSize(), object.getColor());
    Engine3DLinux::Renderer2D::drawQuad(floorPlane.getPosition(), floorPlane.getSize(), floorPlane.getColor());
    // int index = 0;
    // triangle.l1.position = glm::translate(glm::mat4(1.0f), {triangle.l1.position.x, triangle.l1.position.y, 0.0f}) 
	// 								   * glm::scale(glm::mat4(1.0f), {triangle.l1.size.x, triangle.l1.size.y, 1.0f})
	// 								   * index;
    
    glm::vec4 pillarVertices = {-0.5f + 0.1f, -0.5f + 0.1f, 0.0f, 1.0f};
    glm::vec2 tri = glm::translate(glm::mat4(1.f), {triangle.l1.position.x, triangle.l1.position.y, 0.f}) * glm::scale(glm::mat4(1.f), {triangle.l1.position.x, triangle.l1.position.y, 1.f}) * pillarVertices;

    // Engine3DLinux::Ref<Engine3DLinux::Texture2D> texture = Engine3DLinux::Texture2D::Create("assets/textures/GroundTexture.glg");
    // Engine3DLinux::Renderer2D::drawQuad(triangle.l1)
    // Renderer2D::drawQuad(triangle.l1.bottomPosition, triangle.l1.bottomScale, triangleTexture, 1.0, color);
    glm::vec4 color = {1.f, 1.f, 1.f, 1.f};
    Engine3DLinux::Renderer2D::drawQuad(triangle.l1.position, triangle.l1.size, color);
}