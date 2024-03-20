#include <Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>
#include <Engine3DLinux/Renderer2D/Renderer.h>
#include <OpenGL/OpenGLShader.h>
#include <Engine3DLinux/Renderer2D/Renderer2D.h>
#include <Engine3DLinux/Debug/Instrumentor.h>

namespace Engine3DLinux{
	Scope<Renderer::SceneData> Renderer::_sceneData = CreateScope<Renderer::SceneData>();

    void Renderer::init(){
		RENDER_PROFILE_FUNCTION();

        RendererCommand::init();
		Renderer2D::Init(); // Need to initialize 2D renderer before anything.
    }
	
	void Renderer::onWindowResize(uint32_t w, uint32_t h){
		RendererCommand::setViewport(0, 0, w, h);
	}

    void Renderer::beginScene(OrthographicCamera& camera){
        _sceneData->viewProjectionMatrix = camera.getViewProjectionMatrix();
    }

    void Renderer::endScene(){

    }

    void Renderer::submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform){
        shader->bind();
        std::dynamic_pointer_cast<OpenGLShader>(shader)->uploadUniformMat4("u_ViewProjection", _sceneData->viewProjectionMatrix);
        std::dynamic_pointer_cast<OpenGLShader>(shader)->uploadUniformMat4("u_Transform", transform); // whenever we submit, def need to do this per object

        vertexArray->bind();
        RendererCommand::drawIndexed(vertexArray);
    }
};
