#pragma once
#include "Spu/Renderer/Buffer.h"
#include <glad/glad.h>

namespace Spu {
	class OpenGLVertexBuffer : public VertexBuffer {
	public:
		OpenGLVertexBuffer(float* vertices, uint size);
		~OpenGLVertexBuffer() { glDeleteBuffers(1, &mBufferID); }

		virtual void Bind() const override;
		virtual void UnBind() const override;
	
	private:
		uint mBufferID;
	};

	class OpenGLIndexBuffer : public IndexBuffer {
	public:
		OpenGLIndexBuffer(uint* indices, uint count);
		~OpenGLIndexBuffer() { glDeleteBuffers(1, &mBufferID); }

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual uint GetCount() const noexcept override { return mCount; }

	private:
		uint mCount;
		uint mBufferID;
	};
}