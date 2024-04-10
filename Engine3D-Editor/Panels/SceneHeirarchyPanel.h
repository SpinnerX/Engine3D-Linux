#pragma once
#include <Engine3DLinux/Core/core.h>
#include <Engine3DLinux/Scene2D/Scene.h>
#include <Engine3DLinux/Scene2D/Entity.h>

namespace Engine3DLinux{
	/*
	 *
	 * @function setContext
	 * @note setting the scene context.
	 * @note setting up scene heirarchy panel.
	 *
	 * */
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
