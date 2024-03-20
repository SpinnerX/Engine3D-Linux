#include <Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>
#include <Engine3DLinux/interfaces/Texture.h>
#include <Engine3DLinux/Renderer2D/Renderer.h>
#include <OpenGL/OpenGLTexture.h>

namespace Engine3DLinux{

    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height){
		switch (Renderer::getAPI()) {
			case RendererAPI::API::None:
				render_assert(false, "RendererAPI::None is currently not supported!");
				return nullptr;
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLTexture2D>(width, height);
		}
	}

    Ref<Texture2D> Texture2D::Create(const std::string& filepath){
        switch (RendererAPI::getAPI()){
        case RendererAPI::API::None:
            render_core_assert(false, "RenderAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(filepath);
        }

        render_core_assert(false, "Unknown renderer API");
        return nullptr;
    }
};
