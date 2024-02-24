#pragma once
#include <Engine3D/Events/Event.h>

namespace Engine3D{
	
	class ENGINE_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const{ return _keyCode; }

		int GetCategoryFlags() const override{
			return EventCategoryKeyboard | EventCategoryInput;
		}

	protected:
		KeyEvent(int keycode) : _keyCode(keycode) {}

		int _keyCode;
	};

	class ENGINE_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), _repeatCount(repeatCount) {}

		inline int getRepeatCount() const { return _repeatCount; }

		static EventType GetStaticType() { return EventType::KeyPressed; }

		virtual EventType GetEventType() const override { return GetStaticType(); }

		virtual const char* GetName() const override { return "EventType::KeyPressed"; }

		std::string toString() const override{
			return fmt::format("KeyPressedEvent: {} ({} repeats)\n", _keyCode, _repeatCount);
		}

	private:
		int _repeatCount=0;
	};

	class ENGINE_API KeyReleasedEvent : public KeyEvent{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string toString() const override{
			return fmt::format("KeyReleasedEvent: {}\n", _keyCode);
		}

		static EventType GetStaticType() { return EventType::KeyReleased; }

		virtual EventType GetEventType() const override { return GetStaticType(); }

		virtual const char* GetName() const override { return "EventType::KeyReleased"; }
	};
};
