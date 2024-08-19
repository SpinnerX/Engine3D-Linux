#include "SimulationLayer.h"
#include "interfaces/Framebuffer.h"

namespace Engine3DLinux{
    SimulationLayer::SimulationLayer() : Layer("Simulation Layer") {
        FrameBufferSpecifications spec;
        spec.attachments = { FrameBufferTextureFormat::RGBA8, FrameBufferTextureFormat::RED_INTEGER, FrameBufferTextureFormat::DEPTH24STENCIL8 };
        spec.width = 1280;
        spec.height = 720;
    }

    void SimulationLayer::onAttach(){

    }

    void SimulationLayer::onDetach(){}

    void SimulationLayer::onUpdate(Timestep ts){}

    void SimulationLayer::onEvent(Event& e) {}

    void SimulationLayer::onUIRender(){}
};