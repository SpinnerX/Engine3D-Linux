#pragma once
#include <Engine3D/Core/core.h>
#include <Engine3D/Events/Event.h>
#include <Engine3D/Core/EngineLogger.h>

namespace Engine3D{
	/*
	 * @class Layer
	 * @param name is used for debugging purposes.
	 *@TODO Enabling/Disabling layers from being updated/rendering (hiding from layer stack)
	 *
	*/

	class ENGINE_API Layer{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();
		
		// @note when pushing to layer stack, we attach the layer
		virtual void onAttach(){
			coreLogInfo("Default onAttach() called!\n");
		}

		// @note Popping from the stack, we dettach from the layer.
		virtual void onDettach(){
			coreLogWarn("Default onDettach() called!\n");
		}

		virtual void onUpdate(){}

		virtual void onEvent(Event& event){}

		inline const std::string& getName() const { return _debugName; }

		friend std::ostream& operator<<(std::ostream& outs, const Layer* layer){
			return outs << layer->_debugName;
		}
	private:
		std::string _debugName;
	};
};
