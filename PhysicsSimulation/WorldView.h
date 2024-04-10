#pragma once
#include <Engine3DLinux/Core/core.h>
#include <Engine3DLinux/interfaces/Shader.h>
#include <Engine3DLinux/Events/Event.h>
#include <Engine3DLinux/Core/Timestep.h>
#include "SceneObject.h"

/**
 * @name WorldView
 * @note Is going to be our representation of our world
 * @note Our "SimulationLayer" will render our world
 * @note Then we render our object.
 * @note This is supposed to setup all our objects in the world
 *      where our "SceneObject" will interact with.
*/

struct Line{
    Line(const glm::vec3& position, const glm::vec2& size) : position(position), size(size) {}
    glm::vec3 position;
    glm::vec2 size;
};

/**
 * 
 * @name Creating a triangle object
 * 
*/
struct TriangleShapedObject{
    //! @note Triangle consists of three points
    // glm::vec3 top;
    // glm::vec3 bottom;
    // glm::vec3 p3;
    // glm::vec3 size; //! @note Size of the triangle
    Line l1 = Line({0.f, 10.f, 0.f}, {5.f, 15.0f}); // bottom
    Line l2;
    Line l3;
};

class WorldView {
public:
    WorldView();

    void onEvent(Engine3DLinux::Event&);

    void onUpdate(Engine3DLinux::Timestep ts);

    void submit();

private:
    //! @note Plane is going to be our world plane (ground, essentially)
    //! @note So, when we load object into our world, it wont fall infinitely
    //! @note Providing our object with its initial origin when it lands.
    Engine3DLinux::Ref<Engine3DLinux::Shader> plane;
    // Engine3DLinux::Ref<Engine3DLinux::Shader> triangle;
    SceneObject object;
    SceneObject floorPlane;
    TriangleShapedObject triangle;
    glm::vec3 planeHsv = {0.0f, 0.8f, 0.8f};
};