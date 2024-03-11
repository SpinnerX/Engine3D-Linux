#pragma once
#include <Engine3D/Events/Event.h>
#include <sstream>

namespace Engine3D{
	// @class MouseMovedEvent
	// @note contains the pos location of the mouse 
	class ENGINE_API MouseMovedEvent : public Event{
	public:
		MouseMovedEvent(float x, float y) : _mouseX(x), _mouseY(y){}

		inline float GetX() const { return _mouseX; }
		inline float GetY() const { return _mouseY; }

		std::string toString() const override{
			std::stringstream ss;
			ss << fmt::format("MouseMovedEvent: ({}, {})", _mouseX, _mouseY);
            return ss.str();
		}
		
		// In runtime we want to see what event type this is.
        static EventType GetStaticType() { return EventType::MouseMoved; }

        // We need another instance of it, so we know what the actual event type it is.
        virtual EventType GetEventType() const override { return GetStaticType(); }
        
		virtual const char* GetName() const override { return "EventType::MouseMoved"; }

        int GetCategoryFlags() const override{
            return EventCategoryMouse | EventCategoryInput;
        }


	private:
		float _mouseX;
		float _mouseY;
	};

	class ENGINE_API MouseScrolledEvent : public Event{
	public:
        MouseScrolledEvent(float xOffset, float yOffset) : _xOffset(xOffset), _yOffset(yOffset) {}

        inline float GetXOffset() const { return _xOffset; }
        inline float GetYOffset() const { return _yOffset; }

        std::string toString() const override {
            // return formatCpp::format("MouseScrolledEvent: ({}, {})", _xOffset, _yOffset);
            std::stringstream ss;
            ss << fmt::format("MouseScrolledEvent: ({}, {})", _xOffset, _yOffset);
            return ss.str();
        }

        // In runtime we want to see what event type this is.
        static EventType GetStaticType() { return EventType::MouseScrolled; }

        // We need another instance of it, so we know what the actual event type it is.
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "EventType::MouseScrolled"; }

        int GetCategoryFlags() const override{
            return EventCategoryMouse | EventCategoryInput;
        }


    private:
        float _xOffset;
        float _yOffset;
	};

	
	class ENGINE_API MouseButtonEvent : public Event{
	public:
        inline int GetMouseButton() const { return _button; }

        // We want to set by default that whenever we are pressing/releasing the category is that this is
        // mouse and grabbing input
        int GetCategoryFlags() const override{
            return EventCategoryMouse | EventCategoryInput;
        }

    protected:
        // protected because we shouldn't be allowed to create this MouseButtonEvent.
        // Only MouseButtonPressed and MouseButtonReleased can use this.
        MouseButtonEvent(int button) : _button(button) {}

        int _button; // containing our button hhere
	};

	class ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string toString() const override {
            // return formatCpp::format("MouseButtonPressedEvent: {}", _button);
            std::stringstream ss;
            ss << fmt::format("MouseButtonPressedEvent: {}", static_cast<int32_t>(_button));
            return ss.str();
        }

        // In runtime we want to see what event type this is.
        static EventType GetStaticType() { return EventType::MouseButtonPressed; }

        // We need another instance of it, so we know what the actual event type it is.
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "EventType::MouseButtonPressed"; }
	};

	class ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string toString() const override {
            std::stringstream ss;
            ss << fmt::format("MouseButtonReleasedEvent: {}", static_cast<int32_t>(_button));
            return ss.str();
        }

        // In runtime we want to see what event type this is.
        static EventType GetStaticType() { return EventType::MouseButtonReleased; }

        // We need another instance of it, so we know what the actual event type it is.
        virtual EventType GetEventType() const override { return GetStaticType(); }
        virtual const char* GetName() const override { return "EventType::MouseButtonReleased"; }
	};

};
