#include <Engine3D/Core/Application.h>
#include <GLFW/glfw3.h>

namespace Engine3D{

	Application::Application(){
		/* _window = std::unique_ptr<Window>(Window::create()); */
		_window = std::unique_ptr<Window>(Window::create());
		/* _window->setEventCallback(bind_event_function(this, &Application::onWindowClose)); */
		/* _window->setEventCallback(bind_event_function(this, &Application::onWindowClose)); */
		_window->setEventCallback(bind_function(this, &Application::onEvent));
		isRunning = true;
	}

	Application::~Application(){}

	void Application::onEvent(Event& event){
		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<WindowCloseEvent>(bind_function(this, &Application::onWindowClose));
		coreLogTrace("{}", event);
	}

	void Application::Run(){
		while(isRunning){
			/* glClearColor(1, 0, 1, 1); */
			/* glClear(GL_COLOR_BUFFER_BIT); */

			_window->onUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& e){
		isRunning = false;
		return true;
	}
};
