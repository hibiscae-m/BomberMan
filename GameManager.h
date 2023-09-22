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
#include "Player.h"
#include "Bomb.h"
#include "Explosion.h"

static std::vector<std::unique_ptr<Player>> players;
static std::vector<std::unique_ptr<Bomb>> bombs;
static std::vector<sf::Vector2i> bombs_locations;
static std::vector<std::unique_ptr<Explosion>> explosions;
static std::vector<std::unique_ptr<GameTile>> gameTiles;
static std::vector<std::vector<int>> mapLoaded;
static sf::Vector2i mapSize;
static std::vector<std::vector<sf::Vector2f>> availablePositions;

class GameManager {
public:
    GameManager() = delete;
    static void loadMap(int map);
    static void initializePlayers();
    static void drawMap(sf::RenderWindow& window);
    static void drawPlayers(sf::RenderWindow& window);
    static void drawBombs(sf::RenderWindow& window);
    static void drawExplosions(sf::RenderWindow& window);
    static void placeBomb(int indexPositionX, int indexPositionY);
    static void placeExplosion(int indexPositionX, int indexPositionY, int counter = 0, int direction = 0);
    static void damageIndex(int positionIndexX, int positionIndexY);
    static void updateMap(sf::Vector2f position, int caseType);
    static void update(sf::Time deltaTime);
    static void clear();
    static bool isNextCaseFree(sf::Vector2i indexes, int direction);
    static sf::Vector2f translatePositionIndexes(int positionIndexX, int positionIndexY);
    enum MAP {
        First,
        Second
    };
    enum DIRECTIONS {
        Up,
        Down,
        Left,
        Right
    };
    enum CASE_TYPE {
        Indestructible,
        Breakable,
        Passable
    };
};


#endif //DISPLAYMAP_GAMEMANAGER_H
