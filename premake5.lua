project "GLEW"
	kind "StaticLib"
	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	includedirs 
	{
		"include"
	}

	files
	{
		"include/gl/*.h",
		"src/*.c"
	}

	excludes
    {
        "src/glewinfo.c",
        "src/visualinfo.c"
    }

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		defines 
		{ 
			"WIN32",
			"GLEW_STATIC",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"