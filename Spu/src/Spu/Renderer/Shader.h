#pragma once

// There is a problem when include glad.h in this file
//#include <glad/glad.h>

#include <string>

namespace Spu {
	class Shader
	{
	public:
		Shader(std::string_view vs, std::string_view fs);
		~Shader(); // { glDeleteProgram(mShaderID);

		void Bind() const;  //{ glUseProgram(mShaderID); }
		void UnBind() const; // { glUseProgram(0); }
		
	private:
		uint mShaderID;
	};
}

