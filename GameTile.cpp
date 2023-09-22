//
// Created by Marius on 17/08/2023.
//

#include "GameTile.h"
#include "ResourcesManager.h"
#include "GameManager.h"
#include <iostream>

GameTile::GameTile(std::string_view textureLocation, int sizePerTile, int type, int tilePosY, int posX, int posY) :
    sizePerTile(sizePerTile), type(type), tilePosY(tilePosY), posX(posX), posY(posY)
{
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource(textureLocation));
    sprite.setTextureRect(sf::IntRect(type * sizePerTile, tilePosY * sizePerTile, sizePerTile, sizePerTile));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(static_cast<float>(posX) + 16, static_cast<float>(posY) + 16);
}

void GameTile::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::Vector2f GameTile::getPosition() {
    return sprite.getPosition();
}

int GameTile::getType() {
    return type;
}

void GameTile::takeDamage() {
    life--;
}

void GameTile::update(sf::Time deltaTime) {
    if (life == 1) {
        sprite.setColor(sf::Color::Red);
    }
    if (life <= 0) {
        GameManager::updateMap(sprite.getPosition(), GameManager::CASE_TYPE::Passable);
    }
}

std::string_view GameTile::getTextureLocation() {
    return textureLocation;
}

int GameTile::getSizePerTile() {
    return sizePerTile;
}

int GameTile::getTilePosY() {
    return tilePosY;
}

int GameTile::getPosX() {
    return posX;
}

int GameTile::getPosY() {
    return posY;
}

void GameTile::changeType(int caseType) {
    type = caseType;
    sprite.setTextureRect(sf::IntRect(caseType * sizePerTile, tilePosY * sizePerTile, sizePerTile, sizePerTile));
    sprite.setColor(sf::Color::White);
    life = 2;
}

