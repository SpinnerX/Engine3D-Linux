#pragma once
#include <Engine3D/Core/core.h>
#include <string>
#include <functional>
#include <fmt/format.h>
#include <sstream>

namespace Engine3D{
	
	/*
	 * @enum EventType
	 * @note Events in Engine3D currentlly blocking, when an event occurs.
	 * @note Immediately dispatching events
	 * @TODO probably have a better design of operations, like having a buffer events for an event buffer
	 * @note and processing them during the "event" part of the update stage.
	 *
	 *
	 *
	*/

	enum class EventType{
		None=0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	/*
	 * @enum EventCategory
	 * @note Filtering out certain incoming events
	 * @note Receiving events from app into some kind of receiving evcents from application to some event class.
	*/

	enum EventCategory{
		None = 0,
		EventCategoryApplication =		bit(0),
		EventCategoryInput =			bit(1),
		EventCategoryKeyboard =			bit(2),
		EventCategoryMouse =			bit(3),
		EventCategoryMouseButton =		bit(4)
	};

	class ENGINE_API Event{
		friend class EventDispatcher;
	public:
		// @note retrieving specific events
		virtual EventType GetEventType() const = 0;

		virtual const char* GetName() const = 0;

		virtual int GetCategoryFlags() const = 0;

		virtual std::string toString() const { return GetName(); }

		// @note checking the category exists, and is in the current bit.
		inline bool isInCategory(EventCategory category){
			return GetCategoryFlags() & category;
		}

		friend std::ostream& operator<<(std::ostream& outs, const Event& e){
			return outs << e.toString();
		}

	protected:
		bool _handled = false;
	};

	// @class EventDispatcher
	// @note Dispatching system to taking in a specific event
	// @note Receiving an event via template T.
	// @note Creating an instance of this event will call Dispatch<T> from this class
	class EventDispatcher{
		// @TODO Probably make this take a second parameter, like template<T, F> for Dispatch<T, F>
		template<typename T>
		using EventFunction = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : _event(event){}
		
		// @function Dispatch<T>
		// @note T& can be any type of event such as WindowResizeEvent, etc.
		// @note Event must match the type of function being passed into here.
		template<typename T>
		bool Dispatch(EventFunction<T> func){
			if(_event.GetEventType() == T::GetStaticType()){
				_event._handled = func(*(T*)&_event);
				return true;
			}
			return false;
		}

	private:
		Event& _event;
	};

};

namespace fmt{

	/*
	 * @function parse
	 * @function format
	 * @note specialized template for printing out event Event::toString()
	 *
	 *
	 * */
	template<>
	struct formatter<Engine3D::Event>{
		template<typename ParseContext>
		constexpr auto parse(ParseContext& ctx) { return ctx.begin(); }

		auto format(const Engine3D::Event& e, format_context& ctx) const -> format_context::iterator{
			std::stringstream ss;
			ss << e;
			/* return format_to(ctx.out(), "{}", ss.str()); */
			return format_to(ctx.out(), "{}", ss.str());
		}
	};
};
