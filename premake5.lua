workspace "AngA"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "AngA"
	location "AngA"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "aapch.h"
	pchsource "AngA/src/aapch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AA_PLATFORM_WINDOWS",
			"AA_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ANGA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ANGA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ANGA_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"AngA/vendor/spdlog/include",
		"AngA/src"
	}

	links
	{
		"AngA"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ANGA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ANGA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ANGA_DIST"
		optimize "On"