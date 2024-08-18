-- Define the workspace
workspace "Hedron"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Define the Hazel project
project "Hedron"
    location "Hedron"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
    sysincludedirs { "Hedron/vendor/spdlog/include", "Hedron/src" }
    
    -- Apply platform-specific settings for Windows
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines { "HDE_PLATFORM_WINDOWS", "HDE_BUILD_DLL" }
        
        -- Copy the built DLL to the Sandbox project's bin directory
        postbuildcommands { ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") }

    -- Apply platform-specific settings for macOS
    filter "system:macosx"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "15.0"
        defines { "HDE_PLATFORM_MACOS", "HDE_BUILD_DLL" }

        -- Post-build command to copy the built DLL to a specific directory
        postbuildcommands { "cp %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox" }
    
    -- Apply configuration-specific settings
    filter "configurations:Debug"
        defines "HDE_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "HDE_RELEASE"
        optimize "On"
    filter "configurations:Dist"
        defines "HDE_DIST"
        optimize "On"

-- Define the Sandbox project
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
    sysincludedirs { "Hedron/vendor/spdlog/include", "Hedron/src" }
    links { "Hedron" }
    
    -- Apply platform-specific settings for Windows
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines { "HDE_PLATFORM_WINDOWS" }

    -- Apply platform-specific settings for macOS
    filter "system:macosx"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "15.0"
        defines { "HDE_PLATFORM_MACOS", "HDE_BUILD_DLL" }
    
    -- Apply configuration-specific settings
    filter "configurations:Debug"
        defines "HDE_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "HDE_RELEASE"
        optimize "On"
    filter "configurations:Dist"
        defines "HDE_DIST"
        optimize "On"