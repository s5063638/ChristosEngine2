cmake_minimum_required(VERSION 2.6)
project(CHRISTOSENGINE)

include_directories(src)

add_library(rend
	src/rend/Exception.cpp
	src/rend/Context.cpp
	src/rend/Texture.cpp
	src/rend/RenderTexture.cpp
	src/rend/Shader.cpp
	src/rend/Buffer.cpp
  	src/rend/Mesh.cpp
  	src/rend/Util.cpp
)
if(MSVC)
	target_link_libraries(rend glew32 opengl32)
else()
	target_link_libraries(rend GLEW GL)
endif()

add_library(game_engine
	src/game_engine/Engine.cpp
	src/game_engine/Component.cpp
	src/game_engine/Entity.cpp
	src/game_engine/Renderer.cpp
	src/game_engine/Mesh.cpp
	src/game_engine/Resources.cpp
	src/game_engine/Resource.cpp
	src/game_engine/Texture.cpp
	src/game_engine/Shader.cpp
	src/game_engine/game_engine.h
	src/game_engine/Engine.h
	src/game_engine/Component.h
	src/game_engine/Entity.h
	src/game_engine/Keyboard.h
	src/game_engine/Renderer.h
	src/game_engine/Mesh.h
	src/game_engine/Resources.h
	src/game_engine/Resource.h
	src/game_engine/Texture.h
	src/game_engine/Shader.h
	src/game_engine/stb_image.h
)
target_link_libraries(game_engine SDL2 rend)

add_executable(game
	src/game/main.cpp
)
target_link_libraries(game game_engine)
