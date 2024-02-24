#pragma once
#include <cstdint>

namespace Engine3D{
	typedef enum class KeyCode : uint16_t {
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;
}

// From glfw3.h
#define ENGINE_KEY_SPACE           ::RendererEngine::Key::Space
#define ENGINE_KEY_APOSTROPHE      ::RendererEngine::Key::Apostrophe    /* ' */
#define ENGINE_KEY_COMMA           ::RendererEngine::Key::Comma         /* , */
#define ENGINE_KEY_MINUS           ::RendererEngine::Key::Minus         /* - */
#define ENGINE_KEY_PERIOD          ::RendererEngine::Key::Period        /* . */
#define ENGINE_KEY_SLASH           ::RendererEngine::Key::Slash         /* / */
#define ENGINE_KEY_0               ::RendererEngine::Key::D0
#define ENGINE_KEY_1               ::RendererEngine::Key::D1
#define ENGINE_KEY_2               ::RendererEngine::Key::D2
#define ENGINE_KEY_3               ::RendererEngine::Key::D3
#define ENGINE_KEY_4               ::RendererEngine::Key::D4
#define ENGINE_KEY_5               ::RendererEngine::Key::D5
#define ENGINE_KEY_6               ::RendererEngine::Key::D6
#define ENGINE_KEY_7               ::RendererEngine::Key::D7
#define ENGINE_KEY_8               ::RendererEngine::Key::D8
#define ENGINE_KEY_9               ::RendererEngine::Key::D9
#define ENGINE_KEY_SEMICOLON       ::RendererEngine::Key::Semicolon     /* ; */
#define ENGINE_KEY_EQUAL           ::RendererEngine::Key::Equal         /* = */
#define ENGINE_KEY_A               ::RendererEngine::Key::A
#define ENGINE_KEY_B               ::RendererEngine::Key::B
#define ENGINE_KEY_C               ::RendererEngine::Key::C
#define ENGINE_KEY_D               ::RendererEngine::Key::D
#define ENGINE_KEY_E               ::RendererEngine::Key::E
#define ENGINE_KEY_F               ::RendererEngine::Key::F
#define ENGINE_KEY_G               ::RendererEngine::Key::G
#define ENGINE_KEY_H               ::RendererEngine::Key::H
#define ENGINE_KEY_I               ::RendererEngine::Key::I
#define ENGINE_KEY_J               ::RendererEngine::Key::J
#define ENGINE_KEY_K               ::RendererEngine::Key::K
#define ENGINE_KEY_L               ::RendererEngine::Key::L
#define ENGINE_KEY_M               ::RendererEngine::Key::M
#define ENGINE_KEY_N               ::RendererEngine::Key::N
#define ENGINE_KEY_O               ::RendererEngine::Key::O
#define ENGINE_KEY_P               ::RendererEngine::Key::P
#define ENGINE_KEY_Q               ::RendererEngine::Key::Q
#define ENGINE_KEY_R               ::RendererEngine::Key::R
#define ENGINE_KEY_S               ::RendererEngine::Key::S
#define ENGINE_KEY_T               ::RendererEngine::Key::T
#define ENGINE_KEY_U               ::RendererEngine::Key::U
#define ENGINE_KEY_V               ::RendererEngine::Key::V
#define ENGINE_KEY_W               ::RendererEngine::Key::W
#define ENGINE_KEY_X               ::RendererEngine::Key::X
#define ENGINE_KEY_Y               ::RendererEngine::Key::Y
#define ENGINE_KEY_Z               ::RendererEngine::Key::Z
#define ENGINE_KEY_LEFT_BRACKET    ::RendererEngine::Key::LeftBracket   /* [ */
#define ENGINE_KEY_BACKSLASH       ::RendererEngine::Key::Backslash     /* \ */
#define ENGINE_KEY_RIGHT_BRACKET   ::RendererEngine::Key::RightBracket  /* ] */
#define ENGINE_KEY_GRAVE_ACCENT    ::RendererEngine::Key::GraveAccent   /* ` */
#define ENGINE_KEY_WORLD_1         ::RendererEngine::Key::World1        /* non-US #1 */
#define ENGINE_KEY_WORLD_2         ::RendererEngine::Key::World2        /* non-US #2 */

/* Function keys */
#define ENGINE_KEY_ESCAPE          ::RendererEngine::Key::Escape
#define ENGINE_KEY_ENTER           ::RendererEngine::Key::Enter
#define ENGINE_KEY_TAB             ::RendererEngine::Key::Tab
#define ENGINE_KEY_BACKSPACE       ::RendererEngine::Key::Backspace
#define ENGINE_KEY_INSERT          ::RendererEngine::Key::Insert
#define ENGINE_KEY_DELETE          ::RendererEngine::Key::Delete
#define ENGINE_KEY_RIGHT           ::RendererEngine::Key::Right
#define ENGINE_KEY_LEFT            ::RendererEngine::Key::Left
#define ENGINE_KEY_DOWN            ::RendererEngine::Key::Down
#define ENGINE_KEY_UP              ::RendererEngine::Key::Up
#define ENGINE_KEY_PAGE_UP         ::RendererEngine::Key::PageUp
#define ENGINE_KEY_PAGE_DOWN       ::RendererEngine::Key::PageDown
#define ENGINE_KEY_HOME            ::RendererEngine::Key::Home
#define ENGINE_KEY_END             ::RendererEngine::Key::End
#define ENGINE_KEY_CAPS_LOCK       ::RendererEngine::Key::CapsLock
#define ENGINE_KEY_SCROLL_LOCK     ::RendererEngine::Key::ScrollLock
#define ENGINE_KEY_NUM_LOCK        ::RendererEngine::Key::NumLock
#define ENGINE_KEY_PRINT_SCREEN    ::RendererEngine::Key::PrintScreen
#define ENGINE_KEY_PAUSE           ::RendererEngine::Key::Pause
#define ENGINE_KEY_F1              ::RendererEngine::Key::F1
#define ENGINE_KEY_F2              ::RendererEngine::Key::F2
#define ENGINE_KEY_F3              ::RendererEngine::Key::F3
#define ENGINE_KEY_F4              ::RendererEngine::Key::F4
#define ENGINE_KEY_F5              ::RendererEngine::Key::F5
#define ENGINE_KEY_F6              ::RendererEngine::Key::F6
#define ENGINE_KEY_F7              ::RendererEngine::Key::F7
#define ENGINE_KEY_F8              ::RendererEngine::Key::F8
#define ENGINE_KEY_F9              ::RendererEngine::Key::F9
#define ENGINE_KEY_F10             ::RendererEngine::Key::F10
#define ENGINE_KEY_F11             ::RendererEngine::Key::F11
#define ENGINE_KEY_F12             ::RendererEngine::Key::F12
#define ENGINE_KEY_F13             ::RendererEngine::Key::F13
#define ENGINE_KEY_F14             ::RendererEngine::Key::F14
#define ENGINE_KEY_F15             ::RendererEngine::Key::F15
#define ENGINE_KEY_F16             ::RendererEngine::Key::F16
#define ENGINE_KEY_F17             ::RendererEngine::Key::F17
#define ENGINE_KEY_F18             ::RendererEngine::Key::F18
#define ENGINE_KEY_F19             ::RendererEngine::Key::F19
#define ENGINE_KEY_F20             ::RendererEngine::Key::F20
#define ENGINE_KEY_F21             ::RendererEngine::Key::F21
#define ENGINE_KEY_F22             ::RendererEngine::Key::F22
#define ENGINE_KEY_F23             ::RendererEngine::Key::F23
#define ENGINE_KEY_F24             ::RendererEngine::Key::F24
#define ENGINE_KEY_F25             ::RendererEngine::Key::F25

/* Keypad */
#define ENGINE_KEY_KP_0            ::RendererEngine::Key::KP0
#define ENGINE_KEY_KP_1            ::RendererEngine::Key::KP1
#define ENGINE_KEY_KP_2            ::RendererEngine::Key::KP2
#define ENGINE_KEY_KP_3            ::RendererEngine::Key::KP3
#define ENGINE_KEY_KP_4            ::RendererEngine::Key::KP4
#define ENGINE_KEY_KP_5            ::RendererEngine::Key::KP5
#define ENGINE_KEY_KP_6            ::RendererEngine::Key::KP6
#define ENGINE_KEY_KP_7            ::RendererEngine::Key::KP7
#define ENGINE_KEY_KP_8            ::RendererEngine::Key::KP8
#define ENGINE_KEY_KP_9            ::RendererEngine::Key::KP9
#define ENGINE_KEY_KP_DECIMAL      ::RendererEngine::Key::KPDecimal
#define ENGINE_KEY_KP_DIVIDE       ::RendererEngine::Key::KPDivide
#define ENGINE_KEY_KP_MULTIPLY     ::RendererEngine::Key::KPMultiply
#define ENGINE_KEY_KP_SUBTRACT     ::RendererEngine::Key::KPSubtract
#define ENGINE_KEY_KP_ADD          ::RendererEngine::Key::KPAdd
#define ENGINE_KEY_KP_ENTER        ::RendererEngine::Key::KPEnter
#define ENGINE_KEY_KP_EQUAL        ::RendererEngine::Key::KPEqual

#define ENGINE_KEY_LEFT_SHIFT      ::RendererEngine::Key::LeftShift
#define ENGINE_KEY_LEFT_CONTROL    ::RendererEngine::Key::LeftControl
#define ENGINE_KEY_LEFT_ALT        ::RendererEngine::Key::LeftAlt
#define ENGINE_KEY_LEFT_SUPER      ::RendererEngine::Key::LeftSuper
#define ENGINE_KEY_RIGHT_SHIFT     ::RendererEngine::Key::RightShift
#define ENGINE_KEY_RIGHT_CONTROL   ::RendererEngine::Key::RightControl
#define ENGINE_KEY_RIGHT_ALT       ::RendererEngine::Key::RightAlt
#define ENGINE_KEY_RIGHT_SUPER     ::RendererEngine::Key::RightSuper
#define ENGINE_KEY_MENU            ::RendererEngine::Key::Menu
