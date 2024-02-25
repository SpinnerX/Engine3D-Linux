#include <Engine3D/Core/Application.h>
#include <Engine3D/Core/EngineLogger.h>
#include <Engine3D/Core/EntryPoint.h>
#include <Engine3D/Core/LayerStack.h>

class ExampleLayer : public Engine3D::Layer{
public:
	void onUpdate() override {
        clientLogInfo("ExampleLayer::Update");
    }

    void onEvent(Engine3D::Event& event) override{
        clientLogTrace("{}", event);
    }
};

class ExampleApp : public Engine3D::Application{
public:
	ExampleApp() : Application(){
		pushLayer(new ExampleLayer());
		/* coreLogInfo("This is an interesting logger lol\n"); */
	}
};

Engine3D::Application* Engine3D::CreateApplication(){
	return new ExampleApp();
}
