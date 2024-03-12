#pragma once
#include <Engine3D/interfaces/Buffer.h>

namespace Engine3D{
	
	/*
	 *
	 * @class OpenGLVertexBuffer
	 *
	 * API Usage
	 * @note These are different API usage that can be made to vertex's (both usage apply to VertexBuffer and IndexBuffer...)
	 * 1.) OpenGLVertexBuffer vertex = {0.0, 0.f, 0.0f}
	 * 1.1 OpenGLVertexBuffer vertex = VertexBuffer({0.0f, 0.0f, 0.0f});
	 * 2.) OpenGLVertexBuffer* vertex = VertexBuffer::Create(data, size);
	 *
	 *
	 * */
	class OpenGLVertexBuffer : public VertexBuffer{
	public:
		// OpenGLVertexBuffer(const std::initializer_list<float>& vertices);
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		OpenGLVertexBuffer(uint32_t size);

		virtual ~OpenGLVertexBuffer();

		virtual void bind() const override;

		virtual void unbind() const override;

		virtual void setData(const void* data, uint32_t size) override;


	private:
		uint32_t _rendererID; // @note the ID of where we are storing this buffer in OpenGL, since it is required by OpenGL.
		BufferLayout _layout;
	};


	class OpenGLIndexBuffer : public IndexBuffer{
	public:
		OpenGLIndexBuffer(const std::initializer_list<float>& indices);
		OpenGLIndexBuffer(uint32_t* indices, uint32_t size);

		virtual void bind() const override;

		virtual void unbind() const override;
		
		// @return how many indices are in the index buffer.
		virtual uint32_t getCount() const override { return _count; }

	private:
		uint32_t _rendererID;
		uint32_t _count;
	};
};
