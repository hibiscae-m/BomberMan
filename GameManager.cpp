//
// Created by Marius on 17/08/2023.
//

#include "GameManager.h"
#include <memory>
#include "MapFirst.h"
#include <iostream>

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
            mapSize = MapFirst::getMapSize();
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
            availablePositions.emplace_back( gameTiles[gameTiles.size() - 1]->getPosition().x + static_cast<float>(sizePerTile) / 2,
                                         gameTiles[gameTiles.size() - 1]->getPosition().y + static_cast<float>(sizePerTile) / 2 );
        }
    }

    // Getting all 4 corners of a map
    startPositions.push_back(availablePositions[mapSize.x + 1]);
    startPositions.push_back(availablePositions[availablePositions.size() - mapSize.x - 2]);
    startPositions.push_back(availablePositions[mapSize.x * 2 - 2]);
    startPositions.push_back(availablePositions[availablePositions.size() - mapSize.x * 2 + 1]);
}

void GameManager::initializePlayers() {
    players.push_back(std::make_unique<Player>(startPositions[0]));
    players.push_back(std::make_unique<Player>(startPositions[1]));
}

void GameManager::drawPlayers(sf::RenderWindow &window) {
    for (auto& player: players) {
        player->draw(window);
    }
}

void GameManager::update(sf::Time deltaTime) {
    for (auto& player: players) {
        player->update(deltaTime);
    }
}
