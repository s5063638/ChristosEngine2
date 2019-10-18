cmake_minimum_required(VERSION 2.6)
project(CHRISTOSENGINE)

include_directories(src)

add_library(game_engine
	src/game_engine/Engine.cpp
)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game
	SDL2 glew32 opengl32
)

target_link_libraries(game game_engine)