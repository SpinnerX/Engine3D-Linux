#pragma once
#include <Engine3DLinux/Core/core.h>
#include <Engine3DLinux/Core/Layer.h>
#include <Engine3DLinux/Scene2D/Entity.h>
#include <Engine3DLinux/Renderer2D/EditorCamera.h>
#include <Engine3DLinux/Renderer2D/OrthographicCameraController.h>
#include "Panels/SceneHeirarchyPanel.h"
#include <filesystem>
#include <Engine3DLinux/interfaces/Framebuffer.h>
#include <Engine3DLinux/interfaces/VertexArray.h>
#include <Engine3DLinux/interfaces/Shader.h>
#include <array>

namespace Engine3D {
    // class EditorLayer : public Layer {
    // public:
	// 	EditorLayer();
    //     virtual ~EditorLayer() = default;

	// 	void onAttach() override;
	// 	void onDetach() override;

	// 	void onUpdate(Timestep ts) override;

	// 	void onUIRender() override;

	// 	void onEvent(Event& e) override;

	// private:
	// 	// Current Scene
	// 	// @note Should probably have a Scene renderer that will handle all of this? (TODO)
	// 	// @note The engine should handle Scene rendering stuff
	// 	bool onKeyPressed(KeyPressedEvent& e);
	// 	bool onMousePressed(MouseButtonPressedEvent& e);

	// 	void newScene();
	// 	void loadScene();
	// 	void saveAs();

	// 	/* void loadSceneTarget(std::filesystem::path* path); */
	// private:
	// 	//! @note playing and stopping simulation physics.
	// 	void onScenePlay();
	// 	void onSceneStop();

	// private:
	// 	//! @note UI Handler.
	// 	// @TODO may have a UI manager as well.
	// 	// @note Specifically having a UI manager to handle all our UI specific stuff to make it easier to handle.
	// 	void ui_toolbar();

	// private:
	// 	/* OrthographicCameraController cameraController; */
	// 	SceneHeirarchyPanel sceneHeirarchyPanel;
	// 	EditorCamera editorCamera; //! @note Client should be able to have a client and runtime game camera.
	// 	Ref<Scene> activeScene; // @note Our currently active scene within our editor.
	// 	Ref<FrameBuffer> framebuffers;

	// 	bool isPrimaryCamera = true;
	// 	Entity hoveredEntity; // @note Will be used to indicate what entity are we hovering over.
		
	// 	//! @note Probably also want this to be it's own layer because Gizmo we may want this to be expanded later on.
	// 	int gizmoType = -1; // -1 indicates there is no gizmo type specified
		
	// 	glm::vec2 viewportSize = {0.f, 0.f};
	// 	std::array<glm::vec2, 4> viewportBound;

	// 	bool isViewportFocused = false;
	// 	bool isViewportHovered = false;

	// 	enum class SceneState {
	// 		Edit=0, Play=1, Stop=2
	// 	};

	// 	Ref<Texture2D> playIcon;
	// 	Ref<Texture2D> stopIcon;
		
	// 	// @note Our default state when loading the scene is editing.
	// 	SceneState sceneState = SceneState::Edit;

	// };
	class EditorLayer : public Layer{
    public:
		EditorLayer();
	
		virtual ~EditorLayer() = default;

		virtual void onAttach() override;
		virtual void onDetach() override;

		virtual void onUpdate(Timestep ts) override;

		virtual void onUIRender() override;

		virtual void onEvent(Event& e) override;
	
	private:
		bool onKeyPressed(KeyPressedEvent& e);
		bool onMousePressed(MouseButtonPressedEvent& e);

		void newScene();
		void openScene();
		void openSceneTarget(std::filesystem::path* path);
		void saveAs();

	private:
		// @note playing/stopping/simulating scenes
		void onScenePlay();
		void onSceneStop();

	private:
		// @note ui-related function calls

		void ui_toolBar();

	private:
		/* OrthographicCameraController _cameraController; */
    private:
        Ref<VertexArray> _squareVertexArrays;
		Ref<Shader> _flatColorShader;
        bool _isViewportFocused = false;
		bool _isViewportHovered = false;

		Ref<Texture2D> _checkerboardTexture;


		Ref<FrameBuffer> _framebuffers;

		SceneHeirarchyPanel _sceneHeirarchyPanel;
		// ContentBrowserPanel _contentBrowserPanel;

		Ref<Scene> _activeScene;
		bool isPrimaryCamera = true;
		EditorCamera _editorCamera;

		Entity hoveredEntity; // Gives us the entity we are hovering over.
		
		/* uint32_t pixelHoveredValue=0; */

		int _gizmoType = -1; // @note this is going to be the type of operationt he gizmal is going to be.

		glm::vec2 _viewportSize = {0, 0};
		glm::vec2 _viewportBound[2];
		glm::vec4 _squareColor;
		
		enum class SceneState{
			Edit=0, Play=1
		};
		
		// @note Editor Resources
		Ref<Texture2D> _iconPlay;
		Ref<Texture2D> _iconStop;



		SceneState _sceneState = SceneState::Edit;
    };
};
