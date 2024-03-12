#pragma once
#include <Engine3D/Core/core.h>
#include <glm/glm.hpp>

namespace Engine3D{
	
	/*
	 * @class RendererApi
	 *
	 * @function init();
	 * @function setViewport(x, y, width, height);
	 * @function setClearColor(glm::vec4& color);
	 * @function clear();
	 * @function drawIndexed(vertex array, indexCount);
	 *
	 *
	 *
	 */
	class RendererApi{
	public:
		enum class API{
			None = 0,
			OpenGL
		};

		virtual void init();
		
		virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
		
		virtual void setClearColor(glm::vec4&);

		virtual void clear();

		static inline API getApi() { return _api; }


	private:
		static API _api;
	};

};
