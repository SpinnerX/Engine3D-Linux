#pragma once
#include <Engine3D/Core/core.h>
#include <Engine3D/Core/Window.h>
#include <Engine3D/Core/LayerStack.h>

namespace Engine3D{
	
	class ENGINE_API Application{
	public:
		Application();
		~Application();

		void Run();
		
		void onEvent(Event& event);

		void pushLayer(Layer*);
		void pushOverlay(Layer*);

		inline static Application& Get() { return *_instance; }
		inline Window& GetWindow() { return *_window; }

		void close();

	private:
		bool onWindowClose(WindowCloseEvent& e);

	private:
		Scope<Window> _window;
		bool isRunning;
		LayerStack _layerStack;
		static Application* _instance; // @note getting current applications instance
	};

	Application* CreateApplication();
};
