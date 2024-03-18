#include <Engine3DLinux/Core/Application.h>
#include <Engine3DLinux/Core/EntryPoint.h>
#include <Engine3DLinux/interfaces/Layer.h>
#include <Engine3DLinux/Events/InputPoll.h>
#include <Engine3DLinux/Events/KeyEvent.h>

class ExampleLayer : public Engine3DLinux::Layer{
	virtual void onUpdate(Engine3DLinux::Timestep ts) override{
		coreLogInfo("OnUpdate called!");
	}

	virtual void onEvent(Engine3DLinux::Event& e) override{
		coreLogInfo("OnEvent called!");
		if(Engine3DLinux::InputPoll::isKeyPressed(ENGINE_KEY_ESCAPE)){
			coreLogInfo("Escaped Key Pressed!\n");
			Engine3DLinux::Application::Get().close();
		}
		
	}
};



class Application : public Engine3DLinux::Application{
public:
	Application() : Engine3DLinux::Application() {
		pushLayer(new ExampleLayer());
	}

};




Engine3DLinux::Application* Engine3DLinux::CreateApplication(Engine3DLinux::ApplicationCommandLineArgs args){
	return new Application();
}
