#pragma once
#include "Engine3D/Engine3DPrecompiledHeader.h"
#include <Engine3D/Core/core.h>
#include <Engine3D/Events/Event.h>

namespace Engine3D{
    struct WindowProps{
        WindowProps(const std::string& n = "Engine3D", uint32_t w = 1280, uint32_t h = 720) : title(n), width(w), height(h) {}

        std::string title;
        uint32_t width;
        uint32_t height;
    };

    /**
     * 
     * @class Window
     * @note acts as an interface
     * @note the client user will be implementing this class
     * 
    */
    class ENGINE_API Window{
    public:
        using EventCallbackFn = std::function<void(Event& event)>;

        virtual ~Window(){}

        virtual void onUpdate() = 0;

        virtual uint32_t GetWidth() const = 0;

        virtual uint32_t GetHeight() const = 0;

        // @note Window attributes
        virtual void setEventCallback(const EventCallbackFn& callback) = 0;

        virtual void setVSync(bool enabled) = 0;

        virtual bool isVSync() = 0;

		virtual void* getNativeWindow() const = 0;

        static Window* create(const WindowProps& props = WindowProps());
    };
};
