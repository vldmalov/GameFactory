cmake_minimum_required(VERSION 3.28)
project("GameFactory")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
    #set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /WX")
else()
#    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "predefined")
set_property(GLOBAL PROPERTY CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory("GameFactoryLib")
add_subdirectory("Games/SpaceOdyssey")
add_subdirectory("games/Match3")
add_subdirectory("games/SpaceInvaders")