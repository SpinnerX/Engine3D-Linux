#include <Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>
#include <OpenGL/OpenGLBuffer.h>
#include <glad/glad.h>
#include <Engine3DLinux/Debug/Instrumentor.h>

namespace Engine3DLinux{
    /// -------------------------------------------------
    /// --------------- [ Vertex Buffer] ----------------
    /// -------------------------------------------------
    OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size) {
		RENDER_PROFILE_FUNCTION();

        glGenBuffers(1, &_rendererID);
        // glCreateBuffers(1, &_rendererID); // For some reason does not work but glGenBuffers does
        glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }
	
	OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size){
		RENDER_PROFILE_FUNCTION();

		glGenBuffers(1, &_rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW); // Going to work because we know the data is going to be dynamic
	}

    OpenGLVertexBuffer::~OpenGLVertexBuffer() {
		RENDER_PROFILE_FUNCTION();

        glDeleteBuffers(1, &_rendererID);
    }

    void OpenGLVertexBuffer::bind() const {
		RENDER_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
    }

    void OpenGLVertexBuffer::unbind() const {
		RENDER_PROFILE_FUNCTION();

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
	void OpenGLVertexBuffer::setData(const void* data, uint32_t size){
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

    /// -------------------------------------------------
    /// ---------------- [ Index Buffer] ----------------
    /// -------------------------------------------------

    OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count) : _count(count) {
		RENDER_PROFILE_FUNCTION();

        // NOTE: For some reason glCreateBuffers segfaults when used in OpenGLIndexBuffer and OpenGLVertexBuffers!
        glGenBuffers(1, &_rendererID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer(){
		RENDER_PROFILE_FUNCTION();

        glDeleteBuffers(1, &_rendererID);
    }

    void OpenGLIndexBuffer::bind() const{
		RENDER_PROFILE_FUNCTION();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
    }

    void OpenGLIndexBuffer::unbind() const{
		RENDER_PROFILE_FUNCTION();

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
};
