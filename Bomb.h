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
    void update(sf::Time deltaTime);
    sf::Vector2i getCurrentPositionIndexes();
    bool isDestructed() const;
    void callDestruction();
private:
    sf::Sprite sprite;
    sf::Vector2i currentPositionIndexes;
    sf::Time lifetime = sf::seconds(2);
    sf::Time timeSinceSpawned = sf::Time::Zero;
    bool destructed = false;
};


#endif //BOMBERMAN_BOMB_H
