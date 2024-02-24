#pragma once
#include <Engine3D/Core/Window.h>
#include <GLFW/glfw3.h>

namespace Engine3D{

    class OpenGLWindow : public Window{
    public:
        OpenGLWindow(const WindowProps& props);
        virtual ~OpenGLWindow();

        void onUpdate() override;

		inline uint32_t GetWidth() const override { return _data.width; }

        inline uint32_t GetHeight() const override { return _data.height; }

        void setEventCallback(const EventCallbackFn& callback) override{ _data.callback = callback; }

        void setVSync(bool enabled) override;

        bool isVSync() override { return _data.vSync; }

    private:
        virtual void init(const WindowProps& props);
        virtual void shutdown();

    private:
        GLFWwindow* _window;

        // Window data
        // For containing all relative information to thhe window
        // This is so we can pass custom user WindowData to GLFW instead of passing in the entire class
        struct WindowData{
            std::string title;
            unsigned width, height;
            bool vSync;
            EventCallbackFn callback;
        };

        WindowData _data;
    };
};
