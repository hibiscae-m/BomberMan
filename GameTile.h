//
// Created by Marius on 17/08/2023.
//

#ifndef DISPLAYMAP_GAMETILE_H
#define DISPLAYMAP_GAMETILE_H

#include <string_view>
#include <SFML/Graphics.hpp>

class GameTile {
public:
    GameTile() = delete;
    GameTile(std::string_view textureLocation, int sizePerTile, int tilePosX, int tilePosY,
             int posX, int posY, bool passable);
    void draw(sf::RenderWindow& window);
    bool getIfPassable() const { return isPassable; };
private:
    bool isPassable;
    sf::Sprite sprite;
};


#endif //DISPLAYMAP_GAMETILE_H
