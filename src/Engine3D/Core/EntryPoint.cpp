#include <Engine3DLinux/Core/EntryPoint.h>
#include <Engine3DLinux/Core/Application.h>
// if we are on the Windows OS (since windows uses dll files)

// We move this entry point hhere
// How this is able to happen is because with __attribute__((visibility("default")))
// that allows us to create different entry points when creating game engines, and stuff

#ifdef ENGINE_PLATFORM_WINDOWS
  extern Engine3DLinux::Application* Engine3DLinux::CreateApplication();

  int main(int argc, char** argv){

      auto app = Engine3DLinux::CreateApplication();
      app->Run();
      delete app;
  }
#else
  extern Engine3DLinux::Application* Engine3DLinux::CreateApplication(Engine3DLinux::ApplicationCommandLineArgs args);

  int main(int argc, char** argv){
    Engine3DLinux::EngineLogger::Init(); 
    auto app = Engine3DLinux::CreateApplication({argc, argv});
    app->Run();
    delete app;
}
#endif
