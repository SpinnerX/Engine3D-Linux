#include <Engine3DLinux/Core/Application.h>
#include <Engine3DLinux/Core/EntryPoint.h>
#include <Engine3DLinux/interfaces/Layer.h>
#include <Engine3DLinux/Events/InputPoll.h>
#include <Engine3DLinux/Events/KeyEvent.h>

class ExampleLayer : public Engine3DLinux::Layer{
	
	virtual void onUpdate(Engine3DLinux::Timestep ts) override{

	}

	virtual void onEvent(Engine3DLinux::Event& e) override{

		if(Engine3DLinux::InputPoll::isKeyPressed(ENGINE_KEY_ESCAPE)){
			Engine3DLinux::Application::Get().close();
		}
		
	}
};


// @note Creating User application.
// @note Application should also not be called Application
// @note It conflicts with Engine3DLinux::Application
class MyApplication : public Engine3DLinux::Application{
public:
	MyApplication() : Engine3DLinux::Application() {
		pushLayer(new ExampleLayer());
	}

};




Engine3DLinux::Application* Engine3DLinux::CreateApplication(Engine3DLinux::ApplicationCommandLineArgs args){
	return new MyApplication();
}
