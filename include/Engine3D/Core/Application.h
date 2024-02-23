#pragma once
#include <Engine3D/Core/core.h>

namespace Engine3D{
	
	class ENGINE_API Application{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();
};
