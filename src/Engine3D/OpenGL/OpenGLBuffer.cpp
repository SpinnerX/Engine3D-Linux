#include <OpenGL/OpenGLBuffer.h>
#include <glad/glad.h>

namespace Engine3D{

	/// -------------------------------------------------
    /// --------------- [ Vertex Buffer] ----------------
    /// -------------------------------------------------
	
	OpenGLVertexBuffer::OpenGLVertexBuffer(const std::initializer_list<float>& list){
		glGenBuffers(1, &_rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
		std::vector<float> vertices(list);

		glBufferData(GL_ARRAY_BUFFER, list.size(), vertices.data(), GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size){
		printf("Calling OpenGLVertexBuffer that takes in float*!\n");
		glGenBuffers(1, &_rendererID);

        // glCreateBuffers(1, &_rendererID); // For some reason does not work but glGenBuffers does
        glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
		printf("Calling OpenGLVertexBuffer that takes in float*!\n");
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		printf("Calling OpenGLVertexBuffer that takes in float*!\n");
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size){
		glGenBuffers(1, &_rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);

		glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer(){
		glDeleteBuffers(1, &_rendererID);
	}


	void OpenGLVertexBuffer::bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
	}

	void OpenGLVertexBuffer::unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	
	// @note replacing what data we stored in memory with new data we passed using setData
	void OpenGLVertexBuffer::setData(const void* data, uint32_t size){
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}
	


	/// -------------------------------------------------
    /// ---------------- [ Index Buffer] ----------------
    /// -------------------------------------------------
	
	OpenGLIndexBuffer::OpenGLIndexBuffer(const std::initializer_list<float>& data){
		std::vector<float> indices(data);

		glGenBuffers(1, &_rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);

		glBufferData(GL_ARRAY_BUFFER_BINDING, data.size(), indices.data(), GL_STATIC_DRAW);
	}
	
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t size){
		glGenBuffers(1, &_rendererID);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererID);

		glBufferData(GL_ARRAY_BUFFER_BINDING, size, indices, GL_STATIC_DRAW);
	}

	void OpenGLIndexBuffer::bind() const{

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
    }

    void OpenGLIndexBuffer::unbind() const{

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

	
};
