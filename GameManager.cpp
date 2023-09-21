//
// Created by Marius on 17/08/2023.
//

#include "GameManager.h"
#include <memory>
#include "MapFirst.h"

void GameManager::drawMap(sf::RenderWindow &window) {
    for (auto& gameTile: gameTiles) {
        gameTile->draw(window);
    }
}

void GameManager::loadMap(int map) {
    gameTiles.clear();
    std::string_view tileSetLocation{};
    int sizePerTile{};
    switch (map) {
        case MAP::First:
            mapLoaded = MapFirst::getMap();
            tileSetLocation = MapFirst::getTilesetLocation();
            sizePerTile = MapFirst::getSizePerTile();
            break;
        default:
            break;
    }
    for (int i = 0; i < mapLoaded.size(); i++) {
        for (int j = 0; j < mapLoaded[i].size(); j++) {
            gameTiles.push_back(std::make_unique<GameTile>(tileSetLocation, sizePerTile,
                                                           mapLoaded[i][j], 0,
                                                           j * sizePerTile, i * sizePerTile, true));
        }
    }
}
