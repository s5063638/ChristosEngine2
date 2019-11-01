cmake_minimum_required(VERSION 2.6)
project(CHRISTOSENGINE)

include_directories(src)

add_library(game_engine
	src/game_engine/Engine.cpp
	src/game_engine/Component.cpp
	src/game_engine/Entity.cpp
	src/game_engine/TriangleRenderer.cpp
	src/game_engine/game_engine.h
	src/game_engine/Engine.h
	src/game_engine/Component.h
	src/game_engine/Entity.h
	src/game_engine/Keyboard.h
	src/game_engine/TriangleRenderer.h
)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game
	SDL2 glew32 opengl32
)

target_link_libraries(game game_engine)