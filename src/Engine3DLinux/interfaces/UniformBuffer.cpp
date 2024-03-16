#include <Engine3DLinux/interfaces/UniformBuffer.h>
#include <Engine3DLinux/Renderer/Renderer.h>

namespace Engine3DLinux{
	Ref<UniformBuffer> UniformBuffer::create(uint32_t size, uint32_t binding){
		switch (Renderer::getAPI()) {
			case Engine3D::RendererAPI::API::None: assert(false);
			case Engine3D::RendererAPI::API::OpenGL: break;
			default:
				assert(false);
		}
		return nullptr;
	}
};
