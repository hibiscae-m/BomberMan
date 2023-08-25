//
// Created by Marius on 17/08/2023.
//

#include "GameManager.h"
#include <fstream>
#include <sstream>
#include <memory>

void GameManager::drawMap(sf::RenderWindow &window) {
    for (auto& gameTile: gameTiles) {
        gameTile->draw(window);
    }
}

void GameManager::loadMap(std::string_view mapLocation, std::string_view tileSetLocation, int sizePerTile) {
    gameTiles.clear();
    std::vector<std::vector<int>> mapLoaded;
    std::ifstream mapFile(mapLocation);
    if (mapFile.is_open()) {
        while (mapFile.good()) {
            std::string line;
            std::getline(mapFile, line);
            std::vector<int> rowVector;
            for (char i : line) {
                if (std::isdigit(i)) {
                    rowVector.push_back(i - '0'); // Subtracts the 0 char to convert into an integer
                }
            }
            mapLoaded.push_back(rowVector);
        }
    }
    else {
        // handling errors
    }
    mapFile.close();
    for (int i = 0; i < mapLoaded.size(); i++) {
        for (int j = 0; j < mapLoaded[i].size(); j++) {
            gameTiles.push_back(std::make_unique<GameTile>(tileSetLocation, sizePerTile,
                                                           mapLoaded[i][j], 0,
                                                           j * sizePerTile, i * sizePerTile, true));
        }
    }
}
