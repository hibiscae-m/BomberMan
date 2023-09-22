cmake_minimum_required(VERSION 3.26)
project(BomberMan)

set(CMAKE_CXX_STANDARD 20)

add_executable(BomberMan main.cpp
        Game.cpp
        Game.h
        WindowSettings.h
        GameManager.cpp
        GameManager.h
        ResourcesManager.cpp
        ResourcesManager.h
        GameTile.cpp
        GameTile.h
        Player.cpp
        Player.h
        MapFirst.h
        MapFirst.cpp
        Bomb.cpp
        Bomb.h
        Explosion.cpp
        Explosion.h
)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
target_link_libraries(BomberMan PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)