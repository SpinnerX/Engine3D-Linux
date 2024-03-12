#pragma once
#include <Engine3D/Core/core.h>
#include <glm/glm.hpp>
#include <string>


namespace Engine3D{
	
	/*
	 * @class Shader
	 * @note Platform and API agnostic shader interfaces
	 * @note Implementations will vary depending on which API is available such as OpenGL, Vulkan, Direct X, and so forth.
	 * 
	 *
	 *
	 * @note For TODO, we should probably specify what kind of data to set in compile-time rather then runtime.
	 * @note Since as of right now, setting Int, IntArray, Float, Float3, and Float4 are common.
	 * @note Proposing a new change like (or smthing similar to this):
	 Shader<IntArray> shader = Shader::Create(path);
	 *
	*/
	class Shader{
	public:
		virtual ~Shader() = default;

		virtual void bind() const = 0;

		virtual void unbind() const = 0;

		virtual void setInt(const std::string& name, int value) = 0;

		virtual void setIntArray(const std::string& name, int* values, uint32_t count) = 0;

		virtual void setFloat(const std::string& name, float) = 0;

		virtual void setFloat3(const std::string& name, const glm::vec3& value) = 0;

		virtual void setFloat4(const std::string& name, const glm::vec4& value) = 0;

		virtual void setMat4(const std::string& name, const glm::mat4& value) = 0;

		virtual const std::string& getName() const = 0;

		static Ref<Shader> CreateShader(const std::string& path);

		static Ref<Shader> CreateShader(const std::string& name, const std::string& vertexSArc, const std::string& fragmentSrc);
	};

	class ShaderLibrary{
	public:
		void add(const Ref<Shader>& shader);

		void add(const std::string& path);

		Ref<Shader> load(const std::string& path);

		void load(const std::string& name, const std::string& path);

		bool exists(const std::string& name);

	private:
		// @note Contain name corresponding to specific shaders.
		std::unordered_map<std::string, Ref<Shader>> shaders;
	};

};
