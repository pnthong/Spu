#pragma once

#include "Spu/Renderer/GraphicsContext.h"

namespace Spu {
	class SPU_API DirectXContext : public GraphicsContext {
	public:
		DirectXContext() {}
		~DirectXContext() {};

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:

	};
}