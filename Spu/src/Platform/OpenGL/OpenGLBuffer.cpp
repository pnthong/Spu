#include "supch.h"
#include "OpenGLBuffer.h"
//#include <glad/glad.h>

namespace Spu {
	/////////////////////////////////////////////////////////////////////////////
	// VertexBuffer //////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint size)
	{
		// glCreateBuffers will cause an error if we use integrated Intel HD Graphics
		glCreateBuffers(1, &mBufferID);
		//glGenBuffers(1, &mBufferID);
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	/*OpenGLVertexBuffer::~OpenGLVertexBuffer() {
		glDeleteBuffers(1, &mBufferID);
	}*/

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
	}

	void OpenGLVertexBuffer::UnBind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/////////////////////////////////////////////////////////////////////////////
	// IndexBuffer //////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint* indices, uint count)
		: mCount(count) 
	{
		glCreateBuffers(1, &mBufferID);
		//glGenBuffers(1, &mBufferID);
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mCount * sizeof(uint), indices, GL_STATIC_DRAW);
	}

	/*OpenGLIndexBuffer::~OpenGLIndexBuffer() {
		glDeleteBuffers(1, &mBufferID);
	}*/

	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
	}

	void OpenGLIndexBuffer::UnBind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}