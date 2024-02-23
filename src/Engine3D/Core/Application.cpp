#include <Engine3D/Core/Application.h>
#include <stdio.h>

namespace Engine3D{
	Application::Application(){}

	Application::~Application(){}

	void Application::Run(){
		printf("Application::Run() was called!\n");
	}
};
