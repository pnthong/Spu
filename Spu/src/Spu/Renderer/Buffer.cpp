#include "supch.h"
#include "Spu/Renderer/Buffer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Spu/Renderer/Renderer.h"

namespace Spu {
	VertexBuffer* VertexBuffer::Create(float* vertices, uint size)
	{
		switch (Renderer::GetRenderingAPI()) {
			case RendererAPI::None:
				return nullptr;
				break;

			case RendererAPI::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
				break;
		}

		SPU_CORE_ASSERT("Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint* indices, uint count)
	{
		switch (Renderer::GetRenderingAPI()) {
			case RendererAPI::None:
				return nullptr;
				break;

			case RendererAPI::OpenGL:
				return new OpenGLIndexBuffer(indices, count);
				break;
		}

		SPU_CORE_ASSERT("Unknown RendererAPI!");
		return nullptr;
	}
}