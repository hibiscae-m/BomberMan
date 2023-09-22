//
// Created by Marius on 22/09/2023.
//

#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include <SFML/Graphics.hpp>

class Bomb {
public:
    Bomb() = delete;
    Bomb(int indexPositionX, int indexPositionY);
    void draw(sf::RenderWindow& window);
private:
    sf::Sprite sprite;
    sf::Vector2i currentPositionIndexes;
};


#endif //BOMBERMAN_BOMB_H
