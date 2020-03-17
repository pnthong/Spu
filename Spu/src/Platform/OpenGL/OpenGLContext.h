#pragma once

#include "Spu/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Spu {
	class SPU_API OpenGLContext: public GraphicsContext {
	public:
		OpenGLContext(GLFWwindow* window)
			: mWindowHandle(window) { }

		~OpenGLContext() {};

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* mWindowHandle;
	};
}