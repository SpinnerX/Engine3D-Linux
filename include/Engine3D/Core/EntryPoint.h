#pragma once



#ifdef ENGINE_PLATFORM_WINDOWS
#error "Engine3D does not suport windows!"
#else
extern Engine3D::Application* Engine3D::CreateApplication();

 int main(int argc, char** argv){
	auto app = Engine3D::CreateApplication();
	app->Run();
	delete app;
 }
#endif
