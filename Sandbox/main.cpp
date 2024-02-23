#include <Engine3D/Core/Application.h>
#include <Engine3D/Core/EngineLogger.h>
#include <Engine3D/Core/EntryPoint.h>


class ExampleApp : public Engine3D::Application{
public:
	ExampleApp() : Application(){
		coreLogInfo("This is an interesting logger lol\n");
	}
};

Engine3D::Application* Engine3D::CreateApplication(){
	return new ExampleApp();
}
