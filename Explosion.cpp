//
// Created by Marius on 22/09/2023.
//

#include "Explosion.h"
#include "ResourcesManager.h"
#include "GameManager.h"

Explosion::Explosion(int indexPositionX, int indexPositionY, int counter, int direction) :
    currentPositionIndexes(indexPositionX, indexPositionY)
{
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource("resources/explosion.png"));
    sprite.setTextureRect(sf::IntRect({SPRITE_SIZE.x * counter, 0},{SPRITE_SIZE.x, SPRITE_SIZE.y}));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(GameManager::translatePositionIndexes(currentPositionIndexes.x, currentPositionIndexes.y));
    GameManager::damageIndex(currentPositionIndexes.x, currentPositionIndexes.y);
    counter++;
    sf::Vector2i nextPositionIndexes = currentPositionIndexes;
    switch (direction) {
        case GameManager::DIRECTIONS::Up:
            sprite.setRotation(0);
            nextPositionIndexes += { 0, -1 };
            break;
        case GameManager::DIRECTIONS::Down:
            sprite.setRotation(180);
            nextPositionIndexes += { 0, 1 };
            break;
        case GameManager::DIRECTIONS::Left:
            sprite.setRotation(-90);
            nextPositionIndexes += { -1, 0};
            break;
        case GameManager::DIRECTIONS::Right:
            sprite.setRotation(90);
            nextPositionIndexes += { 1, 0};
            break;
    }
    switch (counter) {
        case 1:
            GameManager::placeExplosion(currentPositionIndexes.x, currentPositionIndexes.y - 1, counter, GameManager::DIRECTIONS::Up);
            GameManager::placeExplosion(currentPositionIndexes.x, currentPositionIndexes.y + 1, counter, GameManager::DIRECTIONS::Down);
            GameManager::placeExplosion(currentPositionIndexes.x - 1, currentPositionIndexes.y, counter, GameManager::DIRECTIONS::Left);
            GameManager::placeExplosion(currentPositionIndexes.x + 1, currentPositionIndexes.y, counter, GameManager::DIRECTIONS::Right);
            break;
        case 2:
            if (GameManager::isCaseFree(nextPositionIndexes)) {
                GameManager::placeExplosion(nextPositionIndexes.x, nextPositionIndexes.y, counter, direction);
            }
            else {
                GameManager::damageIndex(nextPositionIndexes.x, nextPositionIndexes.y);
            }
            break;
        default:
            break;
    }
}

void Explosion::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Explosion::update(sf::Time deltaTime) {
    timeSinceSpawned += deltaTime;
    if (timeSinceSpawned >= lifetime) {
        destructed = true;
    }
}

sf::Vector2i Explosion::getCurrentPositionIndexes() {
    return currentPositionIndexes;
}

bool Explosion::isDestructed() const {
    return destructed;
}
