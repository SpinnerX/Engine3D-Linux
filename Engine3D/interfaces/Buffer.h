#pragma once
#include <Engine3D/Core/core.h>

namespace Engine3D{

	/*
	 * @topic API Usage
	 * VertexData vertices = {glm::vec3(-1.0, 0.0, 1.0), glm::vec3(0.f, 0.f, 0.f), glm::vec4(255, 255, 255, 0)};
	 * 
	 * @topic API Usage for vertex buffer
	 *
	 *
	 *
	*/
	
	
	/*
	 *
	 * @class VertexBuffer
	 * @function bind()
	 * @function unbind()
	 * @function setData(void *, uint32_t)
	 *
	 * @function create(float* vertices, uint32_t);
	 * @function create(uint32_t size);
	 * */
	class VertexBuffer{
	public:
		
		virtual void bind();
		virtual void unbind();
		
		
		/*
		 * @function create(data, size)
		 * @note takes in data and it's size when creating the VertexBuffer
		 * @note Function may be API-agnostic
		 * @note Meaning we are checking if we are calling OpenGL, DirectX, or Vulkan...
		 *
		 * */
		static VertexBuffer* create(void* data, size_t);

	private:
	};
};
