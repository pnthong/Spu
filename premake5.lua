workspace "Spu"
    architecture "x64"
	startproject "SandBox"
    
	configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Spu/external/GLFW/include"
IncludeDir["Glad"] = "Spu/external/Glad/include"
IncludeDir["ImGui"] = "Spu/external/imgui"
IncludeDir["glm"] = "Spu/external/glm"

include "Spu/external/GLFW"
include "Spu/external/Glad"
include "Spu/external/imgui"

group "Dependencies"
	include "Spu/external/GLFW"
	include "Spu/external/Glad"
	include "Spu/external/imgui"

group ""

project "Spu"
    location "Spu"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "_%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "_%{prj.name}")

    pchheader "supch.h"
    pchsource "Spu/src/supch.cpp"

    files
    {
        "%{prj.name}/src/**.h",        
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/external/glm/glm/**.hpp",
        "%{prj.name}/external/glm/glm/**.inl"
    }

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
    
	includedirs
    {
		"%{prj.name}/src",
        "%{prj.name}/external/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows" 
        systemversion "latest"

        defines {
            "SPU_PLATFORM_WINDOWS",
            "BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }        

    filter "configurations:Debug"
        defines "SPU_DEBUG"
        runtime "Debug"
        symbols "on"    

    filter "configurations:Release"
        defines "SPU_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SPU_DIST"
        runtime "Release"
        optimize "on"

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "_%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "_%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",        
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Spu/external/spdlog/include",
        "Spu/src",
        "Spu/external",
        "%{IncludeDir.glm}"
    }

    links {
        "Spu"
    }

    filter "system:windows" 
        systemversion "latest"

        defines {
            "SPU_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "SPU_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "SPU_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SPU_DIST"
        runtime "Release"
        optimize "on"