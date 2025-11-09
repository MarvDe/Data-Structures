workspace "DataStructures_Workspace"
    configurations {"Debug", "Release"}

filter "configurations:Debug"
    defines "DEBUG"

filter "configurations:Release"
    defines "NDEBUG"

project "DataStructures_Project"
    kind "ConsoleApp"
    language "C"
    location "build"

    files {
        "src/*.c"
    }

    includedirs "include"
