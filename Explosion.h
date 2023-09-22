//
// Created by Marius on 22/09/2023.
//

#ifndef BOMBERMAN_EXPLOSION_H
#define BOMBERMAN_EXPLOSION_H

#include <SFML/Graphics.hpp>

class Explosion {
public:
    Explosion() = delete;
    Explosion(int indexPositionX, int indexPositionY, Explosion* parent = nullptr, int counter = 0, int direction = 0);
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    sf::Vector2i getCurrentPositionIndexes();
    bool isDestructed() const;
private:
    sf::Sprite sprite;
    const sf::Vector2i SPRITE_SIZE = {32, 32};
    sf::Vector2i currentPositionIndexes;
    sf::Time lifetime = sf::seconds(1);
    sf::Time timeSinceSpawned = sf::Time::Zero;
    bool destructed = false;
};


#endif //BOMBERMAN_EXPLOSION_H
