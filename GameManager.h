//
// Created by Marius on 17/08/2023.
//

#ifndef DISPLAYMAP_GAMEMANAGER_H
#define DISPLAYMAP_GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string_view>
#include <memory>
#include "GameTile.h"
#include "WindowSettings.h"

static std::vector<std::unique_ptr<GameTile>> gameTiles;
static std::vector<std::vector<int>> mapLoaded;

class GameManager {
public:
    GameManager() = delete;
    static void loadMap(int map);
    static void drawMap(sf::RenderWindow& window);
    enum MAP {
        First,
        Second
    };
};


#endif //DISPLAYMAP_GAMEMANAGER_H
