#pragma once

#include "Spu/Core.h"

namespace Spu {
	class SPU_API GraphicsContext {
	public:
		GraphicsContext() {};
		virtual ~GraphicsContext() {};

		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}