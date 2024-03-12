#pragma once
#include <glm/glm.hpp>

namespace Engine3D{
	
	class GraphicsContext{
	public:
		virtual ~GraphicsContext();

		virtual void init() = 0;

		virtual void swapbuffers() = 0;
	};

};
