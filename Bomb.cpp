//
// Created by Marius on 22/09/2023.
//

#include "Bomb.h"
#include "ResourcesManager.h"
#include "GameManager.h"
#include <iostream>

Bomb::Bomb(int indexPositionX, int indexPositionY) {
    std::cout << "Bomb placed" << std::endl;
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource("resources/bomb.png"));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    currentPositionIndexes = {indexPositionX, indexPositionY };
    sprite.setPosition(GameManager::translatePositionIndexes(indexPositionX, indexPositionY));
}

void Bomb::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
