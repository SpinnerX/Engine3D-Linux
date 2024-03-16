#pragma once
#include <Engine3DLinux/Renderer/RenderCommand.h>
#include <Engine3DLinux/Renderer/OrthographicCamera.h>
#include <Engine3DLinux/interfaces/Shader.h>

namespace Engine3DLinux{
    
    // Renderer
    // - The renderer is what allows for bind and unbinding
    // - Only Renderer abstracts away the bind and unbinding functions.
    class Renderer{
    public:

        // Used to initialize our renderer
        // Initialing our renderer command, as well
        static void init();

		static void onWindowResize(uint32_t width, uint32_t height);

        static void beginScene(OrthographicCamera& camera);

        static void endScene();

        // Submitted into a renderer queue
        // Then is evaluated probably in a different thread and will get rendered
        // Adding transform
        static void submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

        inline static RendererAPI::API getAPI() { return RendererAPI::getAPI(); }

    private:
        struct SceneData{
            glm::mat4 viewProjectionMatrix;
        };

        static Scope<Renderer::SceneData> _sceneData;

    };
};
