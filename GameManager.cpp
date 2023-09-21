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

void GameManager::loadMap(std::string_view mapLocation, std::string_view tileSetLocation, int sizePerTile) {
    gameTiles.clear();
    for (int i = 0; i < MapFirst::getMapSize().y; i++) {
        for (int j = 0; j < MapFirst::getMapSize().x; j++) {
            gameTiles.push_back(std::make_unique<GameTile>(tileSetLocation, sizePerTile,
                                                           MapFirst::MAP[i][j], 0,
                                                           j * sizePerTile, i * sizePerTile, true));
        }
    }
}
