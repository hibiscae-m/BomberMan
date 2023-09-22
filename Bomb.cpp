//
// Created by Marius on 22/09/2023.
//

#include "Bomb.h"
#include "ResourcesManager.h"
#include "GameManager.h"

Bomb::Bomb(int indexPositionX, int indexPositionY) {
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource("resources/bomb.png"));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    currentPositionIndexes = {indexPositionX, indexPositionY };
    sprite.setPosition(GameManager::translatePositionIndexes(indexPositionX, indexPositionY));
}

void Bomb::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Bomb::update(sf::Time deltaTime) {
    timeSinceSpawned += deltaTime;
    if (timeSinceSpawned >= lifetime) {
        GameManager::placeExplosion(currentPositionIndexes.x, currentPositionIndexes.y);
        destructed = true;
    }
    if (timeSinceSpawned > lifetime / 2.f) {
        sprite.setColor(sf::Color::Red);
    }
}

sf::Vector2i Bomb::getCurrentPositionIndexes() {
    return currentPositionIndexes;
}

bool Bomb::isDestructed() const {
    return destructed;
}

void Bomb::callDestruction() {
    timeSinceSpawned = lifetime;
}
