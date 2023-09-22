//
// Created by Marius on 21/09/2023.
//

#ifndef BOMBERMAN_MAPFIRST_H
#define BOMBERMAN_MAPFIRST_H

#include <string_view>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class MapFirst {
private:
    static constexpr int WIDTH = 15;
    static constexpr int HEIGHT = 13;
    static constexpr std::string_view TILESET_LOCATION = "resources/map1_tileset.png";
    static constexpr int SIZE_PER_TILE = 32;
public:
    MapFirst() = delete;
    static std::vector<std::vector<int>> getMap();
    static std::string_view getTilesetLocation();
    static int getSizePerTile();
    static sf::Vector2i getMapSize();
private:
    static constexpr int MAP[HEIGHT][WIDTH] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 2, 2, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 2, 0},
            {0, 2, 0, 2, 0, 1, 0, 1, 0, 2, 0, 2, 0, 2, 0},
            {0, 2, 2, 2, 1, 2, 1, 1, 1, 1, 2, 2, 2, 2, 0},
            {0, 2, 0, 1, 0, 1, 0, 2, 0, 2, 0, 2, 0, 2, 0},
            {0, 2, 1, 1, 1, 2, 1, 1, 1, 1, 2, 2, 2, 2, 0},
            {0, 1, 0, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0},
            {0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 0},
            {0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, 2, 0, 2, 0},
            {0, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 0},
            {0, 2, 0, 1, 0, 1, 0, 2, 0, 2, 0, 2, 0, 2, 0},
            {0, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
};


#endif //BOMBERMAN_MAPFIRST_H

