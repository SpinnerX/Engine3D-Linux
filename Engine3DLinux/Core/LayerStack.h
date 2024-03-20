#pragma once
#include <Engine3DLinux/Core/core.h>
#include <Engine3DLinux/Core/Layer.h>


namespace Engine3DLinux{

    // Essentially LayerStack is a wrapper of std::vectors of Layers
    // using vector so we can iterate over.
    // for updates we need to iterate through it
    // Not using Stack because we eventually wanna store layers in the middle.
    // So, like some contiguous stack of layers.
    class ENGINE_API LayerStack{
    public:
        LayerStack();
        ~LayerStack();

        void pushLayer(Layer* layer);
        void pushOverlay(Layer* overlay);
        void popLayer(Layer* layer);
        void popOverlay(Layer* overlay);

        std::vector<Layer *>::iterator begin() { return _layers.begin(); }
        std::vector<Layer *>::iterator end() { return _layers.end(); }
    private:
        std::vector<Layer *> _layers;
       unsigned int _layersInsertIndex = 0;
    };
};