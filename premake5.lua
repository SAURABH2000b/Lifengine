workspace "Lifengine"
	architecture "x64"
	
	--Debug: With debug mode support and logging
	--Release: Faster than Debug with some optimizations and fewer logging
	--Dist: Distrubution mode with utmost optimization and negligible logging
	configurations {"Debug", "Release", "Dist"}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Lifengine/vendor/GLFW/include"

-- Includes the GLFW's premake5.lua file
include "Lifengine/vendor/GLFW"
	
project "Lifengine"
	location "Lifengine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	-- pchsource will be ignored for targets other than Visual Studio
	pchheader "lgpch.h"
	pchsource "Lifengine/src/lgpch.cpp"
	
	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
	
	includedirs {"%{prj.name}/src", "%{prj.name}/vendor/spdlog/include", "%{IncludeDir.GLFW}"}

	-- links function takes the names of projects to link to. opengl32.lib is provided by Visual Studio
	links {"GLFW", "opengl32.lib"}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines {"LG_PLATFORM_WINDOWS", "LG_BUILD_DLL"}
		
		postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")}
		
	filter "configurations:Debug"
		defines "LG_DEBUG"
		defines "LG_ENABLE_ASSERTS"
		--symbols "On": this will ask the compiler to generate a pdb file for the project, that consists of debug information
		symbols "On"
		
	filter "configurations:Release"
		defines "LG_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "LG_DIST"
		optimize "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
	
	includedirs {"Lifengine/vendor/spdlog/include", "Lifengine/src"}
	
	links {"Lifengine"}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines {"LG_PLATFORM_WINDOWS"}
		
	filter "configurations:Debug"
		defines "LG_DEBUG"
		--symbols "On": this will ask the compiler to generate a pdb file for the project, that consists of debug information
		symbols "On"
		
	filter "configurations:Release"
		defines "LG_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "LG_DIST"
		optimize "On"
