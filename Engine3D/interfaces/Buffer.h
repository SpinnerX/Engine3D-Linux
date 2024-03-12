#pragma once
#include <Engine3D/Core/core.h>
#include <string>
#include <vector>

namespace Engine3D{
	
	enum class ShaderDataType : uint8_t {
		None = 0,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Bool
	};

	/*
	 * @topic API Usage
	 * VertexData vertices = {glm::vec3(-1.0, 0.0, 1.0), glm::vec3(0.f, 0.f, 0.f), glm::vec4(255, 255, 255, 0)};
	 * 
	 * @topic API Usage for vertex buffer
	 *
	 *
	 *
	*/


	struct BufferElement{
		BufferElement() = default;
		BufferElement(ShaderDataType t, const std::string& n, bool normalized = false) : name(n), type(t), isNormalized(normalized) {}
		
		uint32_t getComponentCount() const;

		std::string name;
		ShaderDataType type;
		uint32_t offset;
		uint32_t size;
		bool isNormalized;
	};

	/*
	 * @class BufferLayout
	 * @note Helps with how data is layout
	 *
	 *
	 * */
	class BufferLayout{
		using iterator = std::vector<BufferElement>::iterator;
		using const_iterator = std::vector<BufferElement>::const_iterator;
	public:
		BufferLayout() = default;

		BufferLayout(const std::initializer_list<BufferElement>& list) : _elements(list) {
			calculateOffsetAndStride();
		}

		inline uint32_t getStride() const { return stride; }

		iterator begin() { return _elements.begin(); }

		iterator end() { return _elements.end(); }

		const_iterator begin() const { return _elements.begin(); }

		const_iterator end() const { return _elements.end(); }

	private:
		void calculateOffsetAndStride();


	private:
		std::vector<BufferElement> _elements;
		uint32_t stride = 0;
	};
	
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
		
		virtual void bind() const = 0;

		virtual void unbind() const = 0;

		virtual void setData(const void* data, uint32_t size) = 0;
		
		/*
		 * @function create(data, size)
		 * @note takes in data and it's size when creating the VertexBuffer
		 * @note Function may be API-agnostic
		 * @note Meaning we are checking if we are calling OpenGL, DirectX, or Vulkan...
		 * 
		 * @function create(size)
		 * @note Used if the user doesn't specify the data, but the size of the data.
		 * */
		static Ref<VertexBuffer> create(float* data, uint32_t size);

		static Ref<VertexBuffer> create(uint32_t size);
	};

	class IndexBuffer{
	public:
		virtual ~IndexBuffer(){}

		virtual void bind() const = 0;

		virtual void unbind() const = 0;

		virtual uint32_t getCount() const = 0;

		static Ref<IndexBuffer> create(uint32_t* data, uint32_t size);
	};
};
