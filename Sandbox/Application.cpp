#include <Engine3D/Core/Application.h>
#include <Engine3D/Core/EngineLogger.h>
#include <Engine3D/Core/EntryPoint.h>
#include <Engine3D/Core/LayerStack.h>
#include <Engine3D/Events/KeyEvent.h>
#include <Engine3D/Events/InputPoll.h>
#include <Engine3D/Events/KeyCodes.h>
#include <array>

class ExampleLayer : public Engine3D::Layer{
public:
	void onUpdate() override {
        clientLogInfo("ExampleLayer::Update");
    }

    void onEvent(Engine3D::Event& event) override{
		if(Engine3D::InputPoll::isKeyPressed(Engine3D::Key::Escape)){
			Engine3D::Application::Get().close();
		}	
	}

private:

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
