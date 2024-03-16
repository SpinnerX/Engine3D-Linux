#include <Engine3DLinux/interfaces/VertexArray.h>
#include <Engine3DLinux/Renderer/Renderer.h>
#include <OpenGL/OpenGLVertexArray.h>

namespace Engine3DLinux{

    Ref<VertexArray> VertexArray::Create(){
        switch (RendererAPI::getAPI()){
        case RendererAPI::API::None:
            render_core_assert(false, "RenderAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLVertexArray>();
        }

        render_core_assert(false, "Unknown renderer API");
        return nullptr;
    }
};
