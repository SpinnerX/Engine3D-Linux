#include <Engine3DLinux/interfaces/UniformBuffer.h>
#include <Engine3DLinux/Renderer2D/Renderer.h>

namespace Engine3DLinux{
	Ref<UniformBuffer> UniformBuffer::create(uint32_t size, uint32_t binding){
		switch (Renderer::getAPI()) {
			case Engine3DLinux::RendererAPI::API::None: assert(false);
			case Engine3DLinux::RendererAPI::API::OpenGL: break;
			default:
				assert(false);
		}
		return nullptr;
	}
};
