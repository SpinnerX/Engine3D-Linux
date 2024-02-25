#include <Engine3DPrecompiledHeader.h>
#include <Engine3D/Core/LayerStack.h>

namespace Engine3D{
	LayerStack::LayerStack(){
		_layersInsert = _layers.begin();
	}

	LayerStack::~LayerStack(){
		for(Layer* layer : _layers){
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer){
		_layersInsert = _layers.emplace(_layersInsert, layer);
	}

	void LayerStack::pushOverlay(Layer* layer){
		_layers.emplace_back(layer);
	}

	void LayerStack::popLayer(Layer* layer){
		auto iter = std::find(_layers.begin(), _layers.end(), layer);

		if(iter != _layers.end()){
			_layers.erase(iter);
			_layersInsert--;
		}
	}

	void LayerStack::popOverlay(Layer* layer){
		auto iter = std::find(_layers.begin(), _layers.end(), layer);

		if(iter != _layers.end()){
			_layers.erase(iter);
		}
	}
};

