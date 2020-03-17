#include "supch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Spu {
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(mWindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SPU_CORE_ASSERT(status, "Failed to initialize Glad!");

		SU_CORE_INFO("OpenGL Info");
		SU_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		SU_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		SU_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(mWindowHandle);
	}
}