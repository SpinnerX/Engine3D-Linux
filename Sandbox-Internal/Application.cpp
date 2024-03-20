#include <Engine3DLinux/Core/Application.h>
#include <Engine3DLinux/Core/EntryPoint.h>
#include "ExampleLayer3D.h"


class MyApplication : public Engine3DLinux::Application{
public:
	MyApplication() : Engine3DLinux::Application() {
		pushLayer(new Engine3DLinux::ExampleLayer3D());
	}
};




Engine3DLinux::Application* Engine3DLinux::CreateApplication(Engine3DLinux::ApplicationCommandLineArgs args){
	return new MyApplication();
}
