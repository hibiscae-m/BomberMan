//
// Created by Marius on 17/08/2023.
//

#include "GameTile.h"
#include "ResourcesManager.h"

GameTile::GameTile(std::string_view textureLocation, int sizePerTile, int tilePosX, int tilePosY, int posX, int posY, bool passable) :
    isPassable(passable)
{
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource(textureLocation));
    sprite.setTextureRect(sf::IntRect(tilePosX * sizePerTile, tilePosY * sizePerTile, sizePerTile, sizePerTile));
    sprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
}

void GameTile::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
