#include <Engine3D/Core/Application.h>
#include <Engine3D/Core/EngineLogger.h>
#include <Engine3D/Core/EntryPoint.h>
#include <Engine3D/Core/LayerStack.h>
#include <Engine3D/Events/KeyEvent.h>
#include <Engine3D/Events/InputPoll.h>
#include <Engine3D/Events/KeyCodes.h>
#include <Engine3D/OpenGL/OpenGLBuffer.h>
#include <Engine3D/OpenGL/OpenGLShader.h>

class ExampleLayer : public Engine3D::Layer{
public:
	ExampleLayer(){
		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};
		vertexBuffers = Engine3D::VertexBuffer::create(vertices, sizeof(vertices));
	}

	void onUpdate() override {
		
        clientLogInfo("ExampleLayer::Update");
    }

    void onEvent(Engine3D::Event& event) override{
		if(Engine3D::InputPoll::isKeyPressed(Engine3D::Key::Escape)){
			Engine3D::Application::Get().close();
		}	
	}

private:
	Engine3D::Ref<Engine3D::VertexBuffer> vertexBuffers;
	Engine3D::Ref<Engine3D::Shader> shader;
};

class ExampleApp : public Engine3D::Application{
public:
	ExampleApp() : Application(){
		pushLayer(new ExampleLayer());
	}
};

Engine3D::Application* Engine3D::CreateApplication(){
	return new ExampleApp();
}
