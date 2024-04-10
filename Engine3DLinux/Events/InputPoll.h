#pragma once
#include <Engine3DLinux/Core/core.h>
#include <Engine3DLinux/Events/KeyCodes.h>
#include <Engine3DLinux/Events/MouseButtonCodes.h>

namespace Engine3DLinux{

	class ENGINE_API InputPoll {
	public:
		inline static bool isKeyPressed(KeyCode keycode){
			return _instance->isKeyPressedImpl(keycode);
		}
		
		inline static bool isMouseButtonPressed(Mouse button){
			return _instance->isMouseButtonPressedImpl(button);
		}

		inline static glm::vec2 getMousePosition(){
			return _instance->getMousePositionImpl();
		}
		
		inline static float getMouseX(){
			return _instance->getMouseXImpl();
		}

		inline static float getMouseY(){
			return _instance->getMouseYImpl();
		}

	protected:
		virtual bool isKeyPressedImpl(Key keycode) = 0;
		virtual bool isMouseButtonPressedImpl(Mouse button) = 0;
		virtual glm::vec2 getMousePositionImpl() = 0;
		
		virtual float getMouseXImpl() = 0;
		virtual float getMouseYImpl() = 0;

	private:
		static InputPoll* _instance;
	};
};
