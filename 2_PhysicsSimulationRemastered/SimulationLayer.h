#pragma once
#include <Engine3D/Core/core.h>
#include <Engine3D/Events/Event.h>
#include <Engine3D/Core/Timestep.h>
#include <Engine3D/Core/Layer.h>
#include <Engine3D/Scene2D/Scene.h>
#include <Engine3D/Renderer2D/EditorCamera.h>
#include <Engine3D/Renderer2D/OrthographicCameraController.h>
#include <Engine3D/interfaces/Framebuffer.h>
#include <box2d/box2d.h>
#include <functional>
#include <iostream>

namespace Engine3DLinux{
	class SimulationLayer : public Layer{
	public:
		SimulationLayer();

		void onAttach() override;

		void onDetach() override;

		void onUpdate(Timestep ts) override;

		void onEvent(Event& e) override;
		
		void onUIRender() override;

	private:
		template<typename T>
		bool submit(const T&& object){
			*(T *)object();
		}

	private:
		//! @note This will be used for playing the simulation
		//! @note Allowing to interact with our simulation through these helper functions
		void onPlay();

		void onStop();

	private:
		// OrthographicCameraController camera;
        enum class GameState{
            MainMenu = 0, Play = 1, EndSimulation = 2
        };

		Ref<FrameBuffer> framebuffer;
	};
};