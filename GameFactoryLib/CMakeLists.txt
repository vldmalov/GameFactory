set(target_name "GameFactoryLib")
project(GameFactoryLib)
message("Build project: ${target_name}")

include("../Externals/sfml.cmake")

file(GLOB_RECURSE source_files "./Source/*.*")
file(GLOB_RECURSE include_files "./Include/*.*")

set(all_sources ${source_files} ${include_files}
        Source/GameScene/GameObjects/GameObjectComponents/SpriteComponent.cpp
        Include/GameScene/GameObjects/GameObjectComponents/SpriteComponent.h
        Include/Resources/ResourceManager.h
        Include/GameScene/GameObjects/GameObjectComponents/MovementComponents/KinematicsComponent.h
        Source/GameScene/GameObjects/GameObjectComponents/MovementComponents/KinematicsComponent.cpp
        Include/Render/RenderManager.h
        Source/Render/RenderManager.cpp
        Include/Render/IRenderManager.h
        Include/Resources/IResourceManager.h
        Include/GameScene/GameObjects/GameObjectComponents/InputComponent.h
        Include/Input/InputProcessor.h
        Source/Input/InputProcessor.cpp
        Include/Input/IInputProcessor.h
        Source/GameScene/GameObjects/GameObjectComponents/InputComponent.cpp
        Include/GameScene/GameObjects/GameObjectComponents/MovementComponents/CircleMovementComponent.h
        Source/GameScene/GameObjects/GameObjectComponents/MovementComponents/CircleMovementComponent.cpp)
add_library(${target_name} STATIC ${all_sources})

source_group("${target_name}\\Src" FILES ${source_files})
source_group("${target_name}\\Inc" FILES ${include_files})

target_include_directories(${target_name} PUBLIC "./Include" ${sfml_include_dirs})
target_link_libraries(${target_name} PUBLIC ${sfml_libraries})
target_compile_features(${target_name} INTERFACE cxx_std_17)

set_target_properties(${target_name} PROPERTIES FOLDER "GameFactoryLib")
set_target_properties(${target_name} PROPERTIES LINKER_LANGUAGE CXX)