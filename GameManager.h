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

class GameManager {
public:
    GameManager() = delete;
    static void loadMap(std::string_view mapLocation, std::string_view tileSetLocation, int sizePerTile);
    static void drawMap(sf::RenderWindow& window);
};


#endif //DISPLAYMAP_GAMEMANAGER_H
