#pragma once
#include <Engine3D/Core/core.h>
#include <Engine3D/Core/Window.h>

namespace Engine3D{
	
	class ENGINE_API Application{
	public:
		Application();
		~Application();

		void Run();
		
		void onEvent(Event& event);

	private:
		bool onWindowClose(WindowCloseEvent& e);

	private:
		Scope<Window> _window;
		bool isRunning;
	};

	Application* CreateApplication();
};
