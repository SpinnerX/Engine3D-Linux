#include <Engine3D/interfaces/Shader.h>
#include <Engine3D/interfaces/RendererAPI.h>
#include <OpenGL/OpenGLShader.h>

namespace Engine3D{
	Ref<Shader> Shader::CreateShader(const std::string& filepath){
		switch (RendererApi::getApi()) {
			case Engine3D::RendererApi::API::OpenGL:
				return CreateRef<OpenGLShader>(filepath);
			default:
				assert(false);
				return nullptr;
		}

		return nullptr;
	}

	Ref<Shader> Shader::CreateShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc){
		switch (RendererApi::getApi()) {
			case Engine3D::RendererApi::API::OpenGL:
				return CreateRef<OpenGLShader>(name, vertexSrc, fragmentSrc);
			default:
				assert(false);
				return nullptr;
		}

		return nullptr;
	}
};
