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
    GameTile(std::string_view textureLocation, int sizePerTile, int type, int tilePosY, int posX, int posY);
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    sf::Vector2f getPosition();
    int getType();
    void changeType(int caseType);
    std::string_view getTextureLocation();
    int getSizePerTile();
    int getTilePosY();
    int getPosX();
    int getPosY();
    void takeDamage();
private:
    sf::Sprite sprite;
    int life = 2;
    std::string_view textureLocation;
    int sizePerTile;
    int type;
    int tilePosY;
    int posX;
    int posY;
};


#endif //DISPLAYMAP_GAMETILE_H
