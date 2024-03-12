#include <Engine3D/interfaces/Buffer.h>
#include <Engine3D/Core/EngineLogger.h>
#include <OpenGL/OpenGLBuffer.h>
#include <Engine3D/interfaces/RendererAPI.h>

namespace Engine3D{
	uint32_t BufferElement::getComponentCount() const {
		switch (type){
            case ShaderDataType::None: return 0;
            case ShaderDataType::Float:  return 1;
            case ShaderDataType::Float2: return 2;
            case ShaderDataType::Float3: return 3;
            case ShaderDataType::Float4: return 4;
            case ShaderDataType::Mat3:   return 3 * 3;
            case ShaderDataType::Mat4:   return 4 * 4;
            case ShaderDataType::Int:    return 1;
            case ShaderDataType::Int2:   return 2;
            case ShaderDataType::Int3:   return 3;
            case ShaderDataType::Int4:   return 4;
            case ShaderDataType::Bool:   return 1;
			default:
				coreLogError("Unknown ShaderDataType");
				assert(false);
        }
	}

	

	void BufferLayout::calculateOffsetAndStride(){
		uint32_t offset = 0;
        stride = 0;

        // For every element we compute the offset, and while fetching the offset we get the stride.
        for(auto& element : _elements){
            element.offset = offset;
            offset += element.size;
            stride += element.size;
        }
	}

	Ref<VertexBuffer> VertexBuffer::create(float* data, uint32_t size){
		switch (RendererApi::getApi()) {
			case Engine3D::RendererApi::API::OpenGL:
				printf("Using OpenGL API...\n");
				return CreateRef<OpenGLVertexBuffer>(data, size);
			default:
				coreLogError("Unknown API");
				assert(false);
				return nullptr;
		}
	}

	Ref<VertexBuffer> VertexBuffer::create(uint32_t size){
		switch (RendererApi::getApi()) {
			case Engine3D::RendererApi::API::OpenGL:
				printf("Using OpenGL API...\n");
				return CreateRef<OpenGLVertexBuffer>(size);
			default:
				coreLogError("Unknown API");
				assert(false);
				return nullptr;
		}
	}

	Ref<IndexBuffer> IndexBuffer::create(uint32_t* data, uint32_t size){
		switch (RendererApi::getApi()) {
			case Engine3D::RendererApi::API::OpenGL:
				printf("Using OpenGL API...\n");
				return CreateRef<OpenGLIndexBuffer>(data, size);
			default:
				coreLogError("Unknown API");
				assert(false);
				return nullptr;
		}
	}
};
