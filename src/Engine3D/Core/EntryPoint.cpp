#include <Engine3D/Core/EntryPoint.h>
#include <Engine3D/Core/Application.h>
#include <Engine3D/Core/EngineLogger.h>


#ifdef ENGINE_PLATFORM_WINDOWS
#error "Engine3D does not suport windows!"
#else

extern Engine3D::Application* Engine3D::CreateApplication();

 int main(int argc, char** argv){
	Engine3D::EngineLogger::Init();
	auto app = Engine3D::CreateApplication();
	app->Run();
	delete app;
 }
#endif
