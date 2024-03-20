#include <Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>
#include <Engine3DLinux/Renderer2D/RenderCommand.h>
#include <OpenGL/OpenGLRendererAPI.h> // OpenGL draw calls are going to be implemented

namespace Engine3DLinux{
    Scope<RendererAPI> RendererCommand::_rendererAPI = CreateScope<OpenGLRendererAPI>();
};
