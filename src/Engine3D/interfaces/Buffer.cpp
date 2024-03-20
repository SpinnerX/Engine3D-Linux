#define GLM_ENABLE_EXPERIEMENTAL
#include <Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>
#include <Engine3DLinux/interfaces/Buffer.h>
#include <Engine3DLinux/Renderer2D/Renderer.h>
#include <OpenGL/OpenGLBuffer.h>
#include <OpenGL/OpenGLBuffer3D.h>

namespace Engine3DLinux{

    // Now use these functions to decide which renderer API's that we want to use
    // - such as which class to instantiate and utilize.
    Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size){
        switch (RendererAPI::getAPI()){
        case RendererAPI::API::None:
            render_core_assert(false, "RenderAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLVertexBuffer>(vertices, size);
        }
        render_core_assert(false, "Unknown renderer API");
        return nullptr;
    }

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size){
        switch (RendererAPI::getAPI()){
        case RendererAPI::API::None:
            render_core_assert(false, "RenderAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLVertexBuffer>(size);
        }
        render_core_assert(false, "Unknown renderer API");
        return nullptr;
		
	}



	Ref<VertexBuffer3D> VertexBuffer3D::Create(uint32_t size){
		switch (RendererAPI::getAPI()) {
			case Engine3DLinux::RendererAPI::API::None:
				render_core_assert(false, "RenderAPI::None is currently not supported!");
				return nullptr;
			case Engine3DLinux::RendererAPI::API::OpenGL:
				return CreateRef<OpenGLVertexBuffer3D>(size);
		}

        render_core_assert(false, "RenderAPI::None is currently not supported!");
		return nullptr;
	}

	Ref<VertexBuffer3D> VertexBuffer3D::Create(void* data, uint32_t size){
		switch (RendererAPI::getAPI()) {
			case Engine3DLinux::RendererAPI::API::None:
				render_core_assert(false, "RenderAPI::None is currently not supported!");
				return nullptr;
			case Engine3DLinux::RendererAPI::API::OpenGL:
				return CreateRef<OpenGLVertexBuffer3D>(data, size);
		}
		
		render_core_assert(false, "RenderAPI::None is currently not supported!");
		return nullptr;
	}


    Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size){
        switch (RendererAPI::getAPI()){
        case RendererAPI::API::None:
            render_core_assert(false, "RenderAPI::None is currently not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLIndexBuffer>(indices, size);
        }
        render_core_assert(false, "Unknown renderer API");
        return nullptr;
    }
};
