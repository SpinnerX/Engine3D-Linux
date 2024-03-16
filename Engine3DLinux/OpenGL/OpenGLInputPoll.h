#pragma once
#include <Engine3DLinux/Events/InputPoll.h>

namespace Engine3DLinux {
	
	class OpenGLInputPoll : public InputPoll {
	protected:
		bool isKeyPressedImpl(Key keycode) override;

		bool isMouseButtonPressedImpl(Mouse button) override;

		float getMouseXImpl() override;

		float getMouseYImpl() override;

		MousePosition getMousePositionImpl() override;
	};
}