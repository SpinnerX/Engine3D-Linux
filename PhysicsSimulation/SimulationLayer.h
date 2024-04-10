#pragma once
#include <Engine3DLinux/Core/core.h>
#include <Engine3DLinux/Events/Event.h>
#include <Engine3DLinux/Core/Timestep.h>
#include <Engine3DLinux/Core/Layer.h>
#include <Engine3DLinux/Scene2D/Scene.h>
#include <Engine3DLinux/Renderer2D/OrthographicCameraController.h>
#include "WorldView.h"

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
		Engine3DLinux::OrthographicCameraController currentActiveSceneCamera;
		//! @note  Our actual object

        enum class GameState{
            MainMenu = 0, Play = 1, EndSimulation = 2
        };

        GameState state;
        Timestep time;
        WorldView world;
	};
};