#pragma once
#include <cstdint>

namespace RendererEngine{
	typedef enum class MouseCode : uint16_t{
		// From glfw3.h
		Button0                = 0,
		Button1                = 1,
		Button2                = 2,
		Button3                = 3,
		Button4                = 4,
		Button5                = 5,
		Button6                = 6,
		Button7                = 7,

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} Mouse;
	
	// inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	// {
	// 	os << static_cast<int32_t>(mouseCode);
	// 	return os;
	// }
}

#define RENDER_MOUSE_BUTTON_0      ::RendererEngine::Mouse::Button0
#define RENDER_MOUSE_BUTTON_1      ::RendererEngine::Mouse::Button1
#define RENDER_MOUSE_BUTTON_2      ::RendererEngine::Mouse::Button2
#define RENDER_MOUSE_BUTTON_3      ::RendererEngine::Mouse::Button3
#define RENDER_MOUSE_BUTTON_4      ::RendererEngine::Mouse::Button4
#define RENDER_MOUSE_BUTTON_5      ::RendererEngine::Mouse::Button5
#define RENDER_MOUSE_BUTTON_6      ::RendererEngine::Mouse::Button6
#define RENDER_MOUSE_BUTTON_7      ::RendererEngine::Mouse::Button7
#define RENDER_MOUSE_BUTTON_LAST   ::RendererEngine::Mouse::ButtonLast
#define RENDER_MOUSE_BUTTON_LEFT   ::RendererEngine::Mouse::ButtonLeft
#define RENDER_MOUSE_BUTTON_RIGHT  ::RendererEngine::Mouse::ButtonRight
#define RENDER_MOUSE_BUTTON_MIDDLE ::RendererEngine::Mouse::ButtonMiddle