#pragma once
#include <Engine3DLinux/Core/core.h>
#include <Engine3DLinux/Events/Event.h>

namespace Engine3DLinux{
    struct WindowProps{

        WindowProps(const std::string& t="Engine3D Linux", uint32_t w = 1600, uint32_t h = 900) : title(t), width(w), height(h) {}

        std::string  title;
        uint32_t width;
        uint32_t height;
    };

    // @note Window interface that represents a desktop system based window.
    // @note Create Window allowing to create windows that are platform specific.

    /**
    * @class Window
    * @note An interface of creating different Windows that are rendering API agnostic.
    * @note Meaning you may have one using OpenGL, Vulkan, DirectX, etc.
    * 
    * @function onUpdate()
    * @note Each frame or event should be updated through onUpdate()
    */

    class ENGINE_API Window{
    public:
        using EventCallbackFn = std::function<void(Event& event)>;

        virtual ~Window(){}

        virtual void onUpdate() = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        // @note Window Attributes
        virtual void setEventCallback(const EventCallbackFn& callback) = 0;

        virtual void setVSync(bool enabled) = 0;
        virtual bool isVSync() const = 0;

        // @note This will return a GLFW window
        // @note void* is because this could potentially return an HHWindow, GLFWwindow*, etc.
        virtual void* getNativeWindow() const = 0;

        // @note Create Window function allowing us to create windows that may be platform specific.
        static Window* create(const WindowProps& props = WindowProps());

        // @note Still Considering
        // static Window* create(const std::string& name="Engine3D Linux", uint32_t width=1600, uint32_t height=900);
    };
};