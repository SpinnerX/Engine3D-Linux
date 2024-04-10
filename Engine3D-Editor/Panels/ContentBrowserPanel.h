#pragma once
#include <filesystem>
#include <Engine3DLinux/interfaces/Texture.h>

namespace Engine3DLinux{
	/*
	 *
	 *
	 * @class ContentBrowserPanel
	 * @note contents that we will be browsing
	 *
	 *
	 * */

	class ContentBrowserPanel{
	public:
		ContentBrowserPanel();

		void onUIRender();
	private:
		std::filesystem::path _currentDirectory;
		Ref<Texture2D> _directoryIcon;
		Ref<Texture2D> _fileIcon;
	};
};
