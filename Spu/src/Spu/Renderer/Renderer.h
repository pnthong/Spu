#pragma once

namespace Spu {
	enum RendererAPI {
		None = 0,
		OpenGL
	};
	
	class Renderer {
	public:
		static RendererAPI GetRenderingAPI() noexcept { return sRendererAPI; }

	private:
		static RendererAPI sRendererAPI;
	};
}