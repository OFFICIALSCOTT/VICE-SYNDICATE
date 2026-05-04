cmake_minimum_required(VERSION 3.20)
project(VICE_SYNDICATE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add source files
set(SOURCES
    source/main.cpp
    source/engine/core/engine.cpp
    source/engine/renderer/renderer.cpp
    source/engine/world/world_manager.cpp
    source/engine/entities/entity.cpp
    source/engine/input/input_manager.cpp
    source/engine/physics/physics_engine.cpp
    source/engine/audio/audio_manager.cpp
    source/game/player/character.cpp
    source/game/player/inventory.cpp
    source/game/weapons/weapon.cpp
    source/game/vehicles/vehicle.cpp
    source/game/ai/ai_agent.cpp
    source/game/missions/mission_manager.cpp
    source/game/ui/ui_manager.cpp
)

# Add headers
set(HEADERS
    source/engine/core/engine.h
    source/engine/renderer/renderer.h
    source/engine/world/world_manager.h
    source/engine/entities/entity.h
    source/engine/input/input_manager.h
    source/engine/physics/physics_engine.h
    source/engine/audio/audio_manager.h
    source/game/player/character.h
    source/game/player/inventory.h
    source/game/weapons/weapon.h
    source/game/vehicles/vehicle.h
    source/game/ai/ai_agent.h
    source/game/missions/mission_manager.h
    source/game/ui/ui_manager.h
)

# Create executable
add_executable(ViceSyndicate ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(ViceSyndicate PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/source
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glm
)

# Find and link libraries
find_package(OpenGL REQUIRED)
target_link_libraries(ViceSyndicate PRIVATE OpenGL::GL)

# Optional: Add GLFW if available
find_package(glfw3 QUIET)
if(glfw3_FOUND)
    target_link_libraries(ViceSyndicate PRIVATE glfw)
endif()

# Optional: Add GLEW if available
find_package(GLEW QUIET)
if(GLEW_FOUND)
    target_link_libraries(ViceSyndicate PRIVATE GLEW::GLEW)
endif()

# Compiler-specific settings
if(MSVC)
    target_compile_options(ViceSyndicate PRIVATE /W4)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(ViceSyndicate PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Enable testing
enable_testing()
