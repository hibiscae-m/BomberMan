//
// Created by Marius on 16/08/2023.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    explicit Player(sf::Vector2f position = {100, 100});
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime);
private:
    void move(sf::Time deltaTime);
    void playAnimation(sf::Time deltaTime);
    bool isIdle = true;
    sf::Sprite sprite;
    const sf::Vector2i SPRITE_SIZE = {22, 35};
    enum Direction { Down, Side, Up };
    sf::Vector2i animation = {6, Direction::Down};
    sf::Time animationTimePerFrame = sf::seconds(1.f/7);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    float speed = 150.f;
};


#endif //BOMBERMAN_PLAYER_H
