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
    GameTile(std::string_view textureLocation, int sizePerTile, int tilePosX, int tilePosY, int posX, int posY);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();
private:
    sf::Sprite sprite;
};


#endif //DISPLAYMAP_GAMETILE_H
