#pragma once
#include <Engine3D/Core/Layer.h>
#include <imgui/imgui.h>


namespace Engine3D{
	/*
	 * @class ImGuiLayer
	 * @note Creating layer specific for ImGui stuff
	 *
	 * */
	class ENGINE_API ImGuiLayer : public Layer{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach() override;

		void onDettach() override;

		void onUpdate() override;

		virtual void onEvent(Event& event) override;
	};
};
