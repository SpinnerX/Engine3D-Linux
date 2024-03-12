#include <Engine3DPrecompiledHeader.h>
#include <Engine3D/OpenGL/OpenGLInputPoll.h>
#include <Engine3D/Core/Application.h>
#include <GLFW/glfw3.h>

namespace Engine3D{
	InputPoll* InputPoll::_instance = new LinuxInputPoll();

	bool LinuxInputPoll::isKeyPressedImpl(Key keycode){
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().getNativeWindow());

		auto state = glfwGetKey(window, static_cast<int32_t>(keycode));

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool LinuxInputPoll::isMouseButtonPressedImpl(Mouse button){
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().getNativeWindow());

		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));

		return state == GLFW_PRESS;
	}

	float LinuxInputPoll::getMouseXImpl(){
		auto[x, y] = getMousePositionImpl();
		return x;
	}

	float LinuxInputPoll::getMouseYImpl(){
		auto[x, y] = getMousePositionImpl();
		return y;
	}

	MousePosition LinuxInputPoll::getMousePositionImpl(){
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().getNativeWindow());

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		MousePosition position = {(float)xpos, (float)ypos};
		return position;
	}
};
