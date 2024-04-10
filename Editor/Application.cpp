#include <Engine3DLinux/Core/Application.h>
#include <Engine3DLinux/Core/EntryPoint.h>
#include "EditorLayer.h"

namespace Engine3D{
    class EditorApplication : public Application{
    public:
        EditorApplication(ApplicationCommandLineArgs args) : Application("Editor", args) {
            pushLayer(new EditorLayer());
        }

        ~EditorApplication() {}
    };

    Application* CreateApplication(const Engine3D::ApplicationCommandLineArgs args){
		return new EditorApplication(args);
	}
};