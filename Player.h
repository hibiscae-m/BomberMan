//
// Created by Marius on 16/08/2023.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player() = delete;
    Player(int indexPositionX, int indexPositionY);
    void draw(sf::RenderWindow& window);
    void update(sf::Time deltaTime);
private:
    void move();
    void playAnimation(sf::Time deltaTime);
    sf::Sprite sprite;
    const sf::Vector2i SPRITE_SIZE = {22, 35};
    enum Direction { Down, Side, Up };
    sf::Vector2i animation = {6, Direction::Down};
    sf::Time animationTimePerFrame = sf::seconds(1.f/7);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Vector2i currentPositionIndexes;

    sf::Time travelTime = sf::milliseconds(200);
    sf::Time travelling = sf::Time::Zero;
    bool isTravelling = false;
    sf::Clock clockTravel;
};


#endif //BOMBERMAN_PLAYER_H
