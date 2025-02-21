set(target_name "SpaceOdyssey")
project(SpaceOdyssey LANGUAGES CXX)
message("Build project: ${target_name}")

file(GLOB_RECURSE source_files "Source/*.*")
file(GLOB_RECURSE include_files "Include/*.*")

set(all_sources ${source_files} ${include_files})
add_executable(${target_name} WIN32 MACOSX_BUNDLE ${all_sources})

source_group("${target_name}\\Src" FILES ${source_files})
source_group("${target_name}\\Inc" FILES ${include_files})

target_compile_definitions(${target_name} PRIVATE
        PROJECT_NAME="${target_name}"
        RESOURCES_DIR="${PROJECT_SOURCE_DIR}/Resources/")

target_link_libraries(${target_name} "GameFactoryLib")
target_compile_features(${target_name} INTERFACE cxx_std_17)
target_include_directories(${target_name} PRIVATE
        "./Include"
        "./Include/GameObjects"
        "../../common/Include")

set_target_properties(${target_name} PROPERTIES FOLDER "GameFactory")
set_target_properties(${target_name} PROPERTIES LINKER_LANGUAGE CXX)
