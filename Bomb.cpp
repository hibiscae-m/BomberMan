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
