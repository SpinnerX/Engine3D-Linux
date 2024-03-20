#include <Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>
#include <Engine3DLinux/interfaces/Framebuffer.h>
#include <Engine3DLinux/Renderer2D/Renderer.h>
#include <OpenGL/OpenGLFramebuffer.h>
/* #include <Engine3DLinux/platforms/OpenGL/OpenGLFramebuffe_Experiemental.h> */

namespace Engine3DLinux {
	Ref<FrameBuffer> FrameBuffer::Create(const FrameBufferSpecifications &specs){
		switch (Renderer::getAPI()) {
			case RendererAPI::API::None: render_core_assert(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return CreateRef<OpenGLFrameBuffer>(specs);
		}

		render_core_assert(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
