#include <Engine3D/Core/Application.h>
#include <GLFW/glfw3.h>

namespace Engine3D{

	Application* Application::_instance = nullptr;

	Application::Application(){
		_window = std::unique_ptr<Window>(Window::create());
		_instance = this;
		_window->setEventCallback(bind_function(this, &Application::onEvent));
		isRunning = true;
	}

	Application::~Application(){}



	void Application::pushLayer(Layer* layer){
		_layerStack.pushLayer(layer);
		layer->onAttach();
	}
	
	void Application::pushOverlay(Layer* layer){
		_layerStack.pushOverlay(layer);
		layer->onAttach();
	}
	
	void Application::onEvent(Event& event){
		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<WindowCloseEvent>(bind_function(this, &Application::onWindowClose));
		coreLogTrace("{}", event);

		auto iter = _layerStack.end();

		while(iter != _layerStack.begin()){
			(*--iter)->onEvent(event);

            if(event._handled)
				break;
		}
	}

	void Application::Run(){
		while(isRunning){
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for(Layer* layer : _layerStack){
				layer->onUpdate();
			}

			_window->onUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& e){
		isRunning = false;
		return true;
	}
};
