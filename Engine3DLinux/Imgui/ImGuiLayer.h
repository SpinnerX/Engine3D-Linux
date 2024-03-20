#pragma once
#include <Engine3DLinux/Core/Layer.h>
#include <Engine3DLinux/Events/KeyEvent.h>
#include <Engine3DLinux/Events/MouseEvent.h>
#include <imgui/imgui.h>
namespace Engine3DLinux{

    // - This is going to be ImGuiLayer that will come with the engine
    //   to just start rendering debugging stuff or the debugger layer on top of the scene
    class ENGINE_API ImGuiLayer : public Layer{
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void onAttach() override;
        virtual void onDetach() override;

		virtual void onEvent(Event& e) override;

        // - Reason we add these two functions is because we want imgui to be able to start rendering on its own
        // - All I want this to do is to know when to begin rendering and to end rendering.
        // So, it could begin a new window, and stuff like that.
        // - So because we want the layer to enclose with this functionality we are going to need to
        //  render a new window, or somethihng like that.

        void begin();
        void end();

		void setBlockEvents(bool blocks) { _isBlockingEvents = blocks; }
		
		void setDarkThemeColors();

    private:
		bool _isBlockingEvents = true;
        float _time=0.f;
    };
};