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
        case MAP::Second:
            break;
        default:
            break;
    }

    for (int i = 0; i < mapLoaded.size(); i++) {
        std::vector<sf::Vector2f> positionsBuffer;
        for (int j = 0; j < mapLoaded[i].size(); j++) {
            gameTiles.push_back(std::make_unique<GameTile>(tileSetLocation, sizePerTile,
                                                           mapLoaded[i][j], 0,
                                                           j * sizePerTile, i * sizePerTile, true));
            positionsBuffer.emplace_back( gameTiles[gameTiles.size() - 1]->getPosition().x + static_cast<float>(sizePerTile) / 2,
                                         gameTiles[gameTiles.size() - 1]->getPosition().y + static_cast<float>(sizePerTile) / 2 );
        }
        availablePositions.push_back(positionsBuffer);
        positionsBuffer.clear();
    }
}

void GameManager::initializePlayers() {
    players.push_back(std::make_unique<Player>(1, 1));
    players.push_back(std::make_unique<Player>(mapSize.x - 2, mapSize.y - 2));
    players.push_back(std::make_unique<Player>(1, mapSize.y - 2));
    players.push_back(std::make_unique<Player>(mapSize.x - 2, 1));
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

bool GameManager::isNextCaseFree(sf::Vector2i indexes, int direction) {
    switch (direction) {
        case DIRECTIONS::Up:
            if (mapLoaded[indexes.y - 1][indexes.x] != 2) {
                return false;
            }
            break;
        case DIRECTIONS::Down:
            if (mapLoaded[indexes.y + 1][indexes.x] != 2) {
                return false;
            }
            break;
        case DIRECTIONS::Left:
            if (mapLoaded[indexes.y][indexes.x - 1] != 2) {
                return false;
            }
            break;
        case DIRECTIONS::Right:
            if (mapLoaded[indexes.y][indexes.x + 1] != 2) {
                return false;
            }
            break;
        default:
            return false;
    }
    return true;
}

sf::Vector2f GameManager::translatePositionIndexes(int positionIndexX, int positionIndexY) {
    return sf::Vector2f { availablePositions[positionIndexY][positionIndexX] };
}
