#include <Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>
#include <Engine3DLinux/OpenGL/OpenGLInputPoll.h>
#include <Engine3DLinux/Core/Application.h>
#include <GLFW/glfw3.h>

namespace Engine3DLinux{
	InputPoll* InputPoll::_instance = new OpenGLInputPoll();

	bool OpenGLInputPoll::isKeyPressedImpl(Key keycode){
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().getNativeWindow());

		auto state = glfwGetKey(window, static_cast<int32_t>(keycode));

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool OpenGLInputPoll::isMouseButtonPressedImpl(Mouse button){
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().getNativeWindow());

		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));

		return state == GLFW_PRESS;
	}

	float OpenGLInputPoll::getMouseXImpl(){
		return getMousePosition().x;
	}

	float OpenGLInputPoll::getMouseYImpl(){
		return getMousePosition().y;
	}

	glm::vec2 OpenGLInputPoll::getMousePositionImpl(){
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().getNativeWindow());

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return {xpos, ypos};
	}
};