#pragma once
#include <Engine3D/Core/core.h>
#include <Engine3D/Core/Layer.h>

namespace Engine3D{
	
	class ENGINE_API LayerStack{
		using iterator = std::vector<Layer *>::iterator;
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		void popLayer(Layer* layer);
		void popOverlay(Layer* layer);
		
		iterator begin() { return _layers.begin(); }
		iterator end() { return _layers.end(); }

	private:
		std::vector<Layer *> _layers;
		iterator _layersInsert;
	};
};
