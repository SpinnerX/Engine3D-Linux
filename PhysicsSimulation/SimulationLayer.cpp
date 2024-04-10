#include "SimulationLayer.h"
#include <Engine3DLinux/Core/Application.h>
#include <Engine3DLinux/Events/InputPoll.h>
#include "Events/KeyCodes.h"
#include "interfaces/Texture.h"
#include <Engine3DLinux/Renderer2D/Renderer.h>
#include <Engine3DLinux/Renderer2D/Renderer2D.h>
#include <Engine3DLinux/interfaces/Framebuffer.h>
#include <Engine3DLinux/interfaces/Texture.h>

namespace Engine3DLinux{
    SimulationLayer::SimulationLayer() : Layer("Layer #1"), currentActiveSceneCamera(1280.0f/720.0f){
        currentActiveSceneCamera.setZoomLevel(10.0f); // @note Higher the offset, the wider we zoom outwards.
        FrameBufferSpecifications frameBufferData{};
        frameBufferData.width = 1280;
        frameBufferData.height = 720;
    }

    void SimulationLayer::onAttach() {
    }

    void SimulationLayer::onDetach() {}

    void SimulationLayer::onUpdate(Timestep ts) {
        currentActiveSceneCamera.onUpdate(ts);
        world.onUpdate(ts);

        Renderer2D::setClearColor();

        Renderer2D::beginScene(currentActiveSceneCamera.getCamera());
        world.submit(); //! @note Submitting all of our rendering commands from our world
        Renderer2D::endScene();

    }

    void SimulationLayer::onEvent(Event& e) {
        if(InputPoll::isKeyPressed(ENGINE_KEY_ESCAPE)){
            Application::Get().close();
        }

        world.onEvent(e);
        currentActiveSceneCamera.onEvent(e);
    }
    
    void SimulationLayer::onUIRender() {}
};