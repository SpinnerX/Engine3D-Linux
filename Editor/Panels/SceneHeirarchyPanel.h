#pragma once
#include <Engine3DLinux/Core/core.h>
#include <Engine3DLinux/Scene2D/Scene.h>
#include <Engine3DLinux/Scene2D/Entity.h>

namespace Engine3D{
	/*!
	 * @name SceneHeirarchyPanel
	 * @note Contains context
	 * @note Handles rendering the scenes
	 * @note Setting up the Scene
	 * @note Handling how the scene is going to handle the entities
	 * @note Setting context of this scene.
	 * @note drawing components and the given entity nodes.
	 * */
	// class SceneHeirarchyPanel{
	// public:
	// 	SceneHeirarchyPanel() = default;
	// 	SceneHeirarchyPanel(const Ref<Scene>& scene);

	// 	void setContext(const Ref<Scene>& scene);

	// 	void onUIRender();

	// 	Entity getCurrentSelectedEntity() const { return currentSelectedEntity; }

	// 	void setSelectedEntity(Entity entity);

	// private:
	// 	void drawEntity(Entity entity);
	// 	void drawComponents(Entity entity);

	// private:
	// 	Ref<Scene> sceneContext;
	// 	Entity currentSelectedEntity;
	// };
	class SceneHeirarchyPanel{
	public:
		SceneHeirarchyPanel() = default;
		SceneHeirarchyPanel(const Ref<Scene>& scene);

		void setContext(const Ref<Scene>& scene);

		void onUIRender();
		
		Entity getSelectedEntity() const { return _selectionContext; }
		
		void setSelectedEntity(Entity entity);

	private:
		void drawEntityNode(Entity entity);
		void drawComponents(Entity entity);

	private:
		Ref<Scene> _context;
		Entity _selectionContext;
	};

};
