message("External Dependency: SFML")

set(SFML_REPO_PATH "https://github.com/SFML/SFML.git")
set(SFML_REPO_TAG "3.0.0")

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY ${SFML_REPO_PATH}
    GIT_TAG "${SFML_REPO_TAG}"
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(SFML)

set(sfml_libraries "SFML::System" "SFML::Window" "SFML::Graphics" "SFML::Network" "SFML::Audio")
if (WIN32)
    list(APPEND sfml_libraries "SFML::Main")
endif(WIN32)

#foreach(library ${sfml_libraries})
#    set_target_properties(${library} PROPERTIES FOLDER "external/sfml")
#endforeach(library)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "TRUE to build SFML libs ass DLL's" FORCE)