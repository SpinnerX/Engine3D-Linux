#pragma once
#include <Engine3D/interfaces/Shader.h>
#include <GLFW/glfw3.h>

namespace Engine3D{


	class OpenGLShader : public Shader{
	public:
		
		OpenGLShader(const std::string& path);
		OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);

		virtual ~OpenGLShader();

		virtual void bind() const override;

		virtual void unbind() const override;

		virtual const std::string& getName() const override { return _name; }

		virtual void setInt(const std::string& name, int value) override;
		
		virtual void setIntArray(const std::string& name, int* values, uint32_t count) override;

		virtual void setFloat(const std::string& name, float) override;
		
		virtual void setFloat3(const std::string& name, const glm::vec3& value) override;

		virtual void setFloat4(const std::string& name, const glm::vec4& value) override;

		virtual void setMat4(const std::string& name, const glm::mat4& value) override;


	private:
		void uploadUniformInt(const std::string& name, int values);
		void uploadIntArray(const std::string& name, int* values, uint32_t count);
        void uploadUniformFloat(const std::string& name, float values);
        void uploadUniformFloat2(const std::string& name, const glm::vec2& values);
        void uploadUniformFloat3(const std::string& name, const glm::vec3& values);
        void uploadUniformFloat4(const std::string& name, const glm::vec4& values);

        void uploadUniformMat3(const std::string& name, const glm::mat3& matrix);
        void uploadUniformMat4(const std::string& name, const glm::mat4& matrix);

	private:
		std::string readFile(const std::string& path);

		std::unordered_map<GLenum, std::string> preProcess(const std::string& src);

		void compileOrGetVuilkanBinaries(const std::unordered_map<GLenum, std::string>& shaderSrc);
		
		void compileOrGetOpenGLBinaries();

		void createProgram();

	private:
		uint32_t _rendererID;
		std::string _name;

		std::string _filepath;
	};

};
