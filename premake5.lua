workspace "Lifengine"
	architecture "x64"
	
	--Debug: With debug mode support and logging
	--Release: Faster than Debug with some optimizations and fewer logging
	--Dist: Distrubution mode with utmost optimization and negligible logging
	configurations {"Debug", "Release", "Dist"}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Lifengine"
	location "Lifengine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
	
	includedirs {"%{prj.name}/vendor/spdlog/include", "%{prj.name}/src"}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines {"LG_PLATFORM_WINDOWS", "LG_BUILD_DLL"}
		
		postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")}
		
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