#pragma once

namespace Spu {
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {};

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
		
		static VertexBuffer* Create(float* vertices, uint size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {};

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
		virtual uint GetCount() const noexcept = 0;

		static IndexBuffer* Create(uint* indices, uint count);
	};
}

