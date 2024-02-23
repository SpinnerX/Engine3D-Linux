#include <Engine3D/Core/Application.h>
#include <Engine3D/Core/EntryPoint.h>

class ExampleApp : public Engine3D::Application{
public:
	ExampleApp() : Application(){}
};

Engine3D::Application* Engine3D::CreateApplication(){
	return new ExampleApp();
}
