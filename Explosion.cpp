//
// Created by Marius on 22/09/2023.
//

#include "Explosion.h"
#include "ResourcesManager.h"
#include "GameManager.h"

Explosion::Explosion(int indexPositionX, int indexPositionY, int counter, int direction) {
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource("resources/explosion.png"));
    sprite.setTextureRect(sf::IntRect({SPRITE_SIZE.x * counter, 0},{SPRITE_SIZE.x, SPRITE_SIZE.y}));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    currentPositionIndexes = {indexPositionX, indexPositionY };
    counter++;
    if (counter == 1) {
        if (GameManager::isNextCaseFree({indexPositionX, indexPositionY}, GameManager::DIRECTIONS::Up)) {
            GameManager::placeExplosion(indexPositionX, indexPositionY, counter, GameManager::DIRECTIONS::Up);
        }
        if (GameManager::isNextCaseFree({indexPositionX, indexPositionY}, GameManager::DIRECTIONS::Down)) {
            GameManager::placeExplosion(indexPositionX, indexPositionY, counter, GameManager::DIRECTIONS::Down);
        }
        if (GameManager::isNextCaseFree({indexPositionX, indexPositionY}, GameManager::DIRECTIONS::Left)) {
            GameManager::placeExplosion(indexPositionX, indexPositionY, counter, GameManager::DIRECTIONS::Left);
        }
        if (GameManager::isNextCaseFree({indexPositionX, indexPositionY}, GameManager::DIRECTIONS::Right)) {
            GameManager::placeExplosion(indexPositionX, indexPositionY, counter, GameManager::DIRECTIONS::Right);
        }
    }
    else {
        if (direction == GameManager::DIRECTIONS::Up) {
            indexPositionY--;
        }
        if (direction == GameManager::DIRECTIONS::Down) {
            sprite.setRotation(180);
            indexPositionY++;
        }
        if (direction == GameManager::DIRECTIONS::Left) {
            sprite.setRotation(-90);
            indexPositionX--;
        }
        if (direction == GameManager::DIRECTIONS::Right) {
            sprite.setRotation(90);
            indexPositionX++;
        }
        if (counter <= 2) {
            if (GameManager::isNextCaseFree({indexPositionX, indexPositionY}, direction)) {
                GameManager::placeExplosion(indexPositionX, indexPositionY, counter, direction);
            }
        }
    }
    sprite.setPosition(GameManager::translatePositionIndexes(indexPositionX, indexPositionY));
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
