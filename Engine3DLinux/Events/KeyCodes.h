#pragma once
#include <cstdint>

namespace Engine3DLinux{
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
#define ENGINE_KEY_SPACE           ::Engine3DLinux::Key::Space
#define ENGINE_KEY_APOSTROPHE      ::Engine3DLinux::Key::Apostrophe    /* ' */
#define ENGINE_KEY_COMMA           ::Engine3DLinux::Key::Comma         /* , */
#define ENGINE_KEY_MINUS           ::Engine3DLinux::Key::Minus         /* - */
#define ENGINE_KEY_PERIOD          ::Engine3DLinux::Key::Period        /* . */
#define ENGINE_KEY_SLASH           ::Engine3DLinux::Key::Slash         /* / */
#define ENGINE_KEY_0               ::Engine3DLinux::Key::D0
#define ENGINE_KEY_1               ::Engine3DLinux::Key::D1
#define ENGINE_KEY_2               ::Engine3DLinux::Key::D2
#define ENGINE_KEY_3               ::Engine3DLinux::Key::D3
#define ENGINE_KEY_4               ::Engine3DLinux::Key::D4
#define ENGINE_KEY_5               ::Engine3DLinux::Key::D5
#define ENGINE_KEY_6               ::Engine3DLinux::Key::D6
#define ENGINE_KEY_7               ::Engine3DLinux::Key::D7
#define ENGINE_KEY_8               ::Engine3DLinux::Key::D8
#define ENGINE_KEY_9               ::Engine3DLinux::Key::D9
#define ENGINE_KEY_SEMICOLON       ::Engine3DLinux::Key::Semicolon     /* ; */
#define ENGINE_KEY_EQUAL           ::Engine3DLinux::Key::Equal         /* = */
#define ENGINE_KEY_A               ::Engine3DLinux::Key::A
#define ENGINE_KEY_B               ::Engine3DLinux::Key::B
#define ENGINE_KEY_C               ::Engine3DLinux::Key::C
#define ENGINE_KEY_D               ::Engine3DLinux::Key::D
#define ENGINE_KEY_E               ::Engine3DLinux::Key::E
#define ENGINE_KEY_F               ::Engine3DLinux::Key::F
#define ENGINE_KEY_G               ::Engine3DLinux::Key::G
#define ENGINE_KEY_H               ::Engine3DLinux::Key::H
#define ENGINE_KEY_I               ::Engine3DLinux::Key::I
#define ENGINE_KEY_J               ::Engine3DLinux::Key::J
#define ENGINE_KEY_K               ::Engine3DLinux::Key::K
#define ENGINE_KEY_L               ::Engine3DLinux::Key::L
#define ENGINE_KEY_M               ::Engine3DLinux::Key::M
#define ENGINE_KEY_N               ::Engine3DLinux::Key::N
#define ENGINE_KEY_O               ::Engine3DLinux::Key::O
#define ENGINE_KEY_P               ::Engine3DLinux::Key::P
#define ENGINE_KEY_Q               ::Engine3DLinux::Key::Q
#define ENGINE_KEY_R               ::Engine3DLinux::Key::R
#define ENGINE_KEY_S               ::Engine3DLinux::Key::S
#define ENGINE_KEY_T               ::Engine3DLinux::Key::T
#define ENGINE_KEY_U               ::Engine3DLinux::Key::U
#define ENGINE_KEY_V               ::Engine3DLinux::Key::V
#define ENGINE_KEY_W               ::Engine3DLinux::Key::W
#define ENGINE_KEY_X               ::Engine3DLinux::Key::X
#define ENGINE_KEY_Y               ::Engine3DLinux::Key::Y
#define ENGINE_KEY_Z               ::Engine3DLinux::Key::Z
#define ENGINE_KEY_LEFT_BRACKET    ::Engine3DLinux::Key::LeftBracket   /* [ */
#define ENGINE_KEY_BACKSLASH       ::Engine3DLinux::Key::Backslash     /* \ */
#define ENGINE_KEY_RIGHT_BRACKET   ::Engine3DLinux::Key::RightBracket  /* ] */
#define ENGINE_KEY_GRAVE_ACCENT    ::Engine3DLinux::Key::GraveAccent   /* ` */
#define ENGINE_KEY_WORLD_1         ::Engine3DLinux::Key::World1        /* non-US #1 */
#define ENGINE_KEY_WORLD_2         ::Engine3DLinux::Key::World2        /* non-US #2 */

/* Function keys */
#define ENGINE_KEY_ESCAPE          ::Engine3DLinux::Key::Escape
#define ENGINE_KEY_ENTER           ::Engine3DLinux::Key::Enter
#define ENGINE_KEY_TAB             ::Engine3DLinux::Key::Tab
#define ENGINE_KEY_BACKSPACE       ::Engine3DLinux::Key::Backspace
#define ENGINE_KEY_INSERT          ::Engine3DLinux::Key::Insert
#define ENGINE_KEY_DELETE          ::Engine3DLinux::Key::Delete
#define ENGINE_KEY_RIGHT           ::Engine3DLinux::Key::Right
#define ENGINE_KEY_LEFT            ::Engine3DLinux::Key::Left
#define ENGINE_KEY_DOWN            ::Engine3DLinux::Key::Down
#define ENGINE_KEY_UP              ::Engine3DLinux::Key::Up
#define ENGINE_KEY_PAGE_UP         ::Engine3DLinux::Key::PageUp
#define ENGINE_KEY_PAGE_DOWN       ::Engine3DLinux::Key::PageDown
#define ENGINE_KEY_HOME            ::Engine3DLinux::Key::Home
#define ENGINE_KEY_END             ::Engine3DLinux::Key::End
#define ENGINE_KEY_CAPS_LOCK       ::Engine3DLinux::Key::CapsLock
#define ENGINE_KEY_SCROLL_LOCK     ::Engine3DLinux::Key::ScrollLock
#define ENGINE_KEY_NUM_LOCK        ::Engine3DLinux::Key::NumLock
#define ENGINE_KEY_PRINT_SCREEN    ::Engine3DLinux::Key::PrintScreen
#define ENGINE_KEY_PAUSE           ::Engine3DLinux::Key::Pause
#define ENGINE_KEY_F1              ::Engine3DLinux::Key::F1
#define ENGINE_KEY_F2              ::Engine3DLinux::Key::F2
#define ENGINE_KEY_F3              ::Engine3DLinux::Key::F3
#define ENGINE_KEY_F4              ::Engine3DLinux::Key::F4
#define ENGINE_KEY_F5              ::Engine3DLinux::Key::F5
#define ENGINE_KEY_F6              ::Engine3DLinux::Key::F6
#define ENGINE_KEY_F7              ::Engine3DLinux::Key::F7
#define ENGINE_KEY_F8              ::Engine3DLinux::Key::F8
#define ENGINE_KEY_F9              ::Engine3DLinux::Key::F9
#define ENGINE_KEY_F10             ::Engine3DLinux::Key::F10
#define ENGINE_KEY_F11             ::Engine3DLinux::Key::F11
#define ENGINE_KEY_F12             ::Engine3DLinux::Key::F12
#define ENGINE_KEY_F13             ::Engine3DLinux::Key::F13
#define ENGINE_KEY_F14             ::Engine3DLinux::Key::F14
#define ENGINE_KEY_F15             ::Engine3DLinux::Key::F15
#define ENGINE_KEY_F16             ::Engine3DLinux::Key::F16
#define ENGINE_KEY_F17             ::Engine3DLinux::Key::F17
#define ENGINE_KEY_F18             ::Engine3DLinux::Key::F18
#define ENGINE_KEY_F19             ::Engine3DLinux::Key::F19
#define ENGINE_KEY_F20             ::Engine3DLinux::Key::F20
#define ENGINE_KEY_F21             ::Engine3DLinux::Key::F21
#define ENGINE_KEY_F22             ::Engine3DLinux::Key::F22
#define ENGINE_KEY_F23             ::Engine3DLinux::Key::F23
#define ENGINE_KEY_F24             ::Engine3DLinux::Key::F24
#define ENGINE_KEY_F25             ::Engine3DLinux::Key::F25

/* Keypad */
#define ENGINE_KEY_KP_0            ::Engine3DLinux::Key::KP0
#define ENGINE_KEY_KP_1            ::Engine3DLinux::Key::KP1
#define ENGINE_KEY_KP_2            ::Engine3DLinux::Key::KP2
#define ENGINE_KEY_KP_3            ::Engine3DLinux::Key::KP3
#define ENGINE_KEY_KP_4            ::Engine3DLinux::Key::KP4
#define ENGINE_KEY_KP_5            ::Engine3DLinux::Key::KP5
#define ENGINE_KEY_KP_6            ::Engine3DLinux::Key::KP6
#define ENGINE_KEY_KP_7            ::Engine3DLinux::Key::KP7
#define ENGINE_KEY_KP_8            ::Engine3DLinux::Key::KP8
#define ENGINE_KEY_KP_9            ::Engine3DLinux::Key::KP9
#define ENGINE_KEY_KP_DECIMAL      ::Engine3DLinux::Key::KPDecimal
#define ENGINE_KEY_KP_DIVIDE       ::Engine3DLinux::Key::KPDivide
#define ENGINE_KEY_KP_MULTIPLY     ::Engine3DLinux::Key::KPMultiply
#define ENGINE_KEY_KP_SUBTRACT     ::Engine3DLinux::Key::KPSubtract
#define ENGINE_KEY_KP_ADD          ::Engine3DLinux::Key::KPAdd
#define ENGINE_KEY_KP_ENTER        ::Engine3DLinux::Key::KPEnter
#define ENGINE_KEY_KP_EQUAL        ::Engine3DLinux::Key::KPEqual

#define ENGINE_KEY_LEFT_SHIFT      ::Engine3DLinux::Key::LeftShift
#define ENGINE_KEY_LEFT_CONTROL    ::Engine3DLinux::Key::LeftControl
#define ENGINE_KEY_LEFT_ALT        ::Engine3DLinux::Key::LeftAlt
#define ENGINE_KEY_LEFT_SUPER      ::Engine3DLinux::Key::LeftSuper
#define ENGINE_KEY_RIGHT_SHIFT     ::Engine3DLinux::Key::RightShift
#define ENGINE_KEY_RIGHT_CONTROL   ::Engine3DLinux::Key::RightControl
#define ENGINE_KEY_RIGHT_ALT       ::Engine3DLinux::Key::RightAlt
#define ENGINE_KEY_RIGHT_SUPER     ::Engine3DLinux::Key::RightSuper
#define ENGINE_KEY_MENU            ::Engine3DLinux::Key::Menu
