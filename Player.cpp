//
// Created by Marius on 16/08/2023.
//

#include "Player.h"
#include "ResourcesManager.h"
#include "GameManager.h"

Player::Player(int indexPositionX, int indexPositionY) {
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource("resources/player.png"));
    sprite.setTextureRect(sf::IntRect({animation.x * SPRITE_SIZE.x, animation.y * SPRITE_SIZE.y},
                                      {SPRITE_SIZE.x, SPRITE_SIZE.y}));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    currentPositionIndexes = {indexPositionX, indexPositionY };
    sprite.setPosition(GameManager::translatePositionIndexes(indexPositionX, indexPositionY));
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::update(const sf::Time deltaTime) {
    if (!isTravelling) {
        clockTravel.restart();
        move();
    }
    else {
        travelling += clockTravel.restart();
        if (travelling >= travelTime) {
            isTravelling = false;
            travelling = sf::Time::Zero;
        }
    }
    playAnimation(deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        GameManager::placeBomb(currentPositionIndexes.x, currentPositionIndexes.y);
    }
}

void Player::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        isTravelling = true;
        animation.y = Direction::Up;
        if (GameManager::isCaseFree({currentPositionIndexes.x, currentPositionIndexes.y - 1})) {
            currentPositionIndexes = { currentPositionIndexes.x, currentPositionIndexes.y - 1 };
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        isTravelling = true;
        animation.y = Direction::Down;
        if (GameManager::isCaseFree({currentPositionIndexes.x, currentPositionIndexes.y + 1})) {
            currentPositionIndexes = { currentPositionIndexes.x, currentPositionIndexes.y + 1 };
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        isTravelling = true;
        animation.y = Direction::Side;
        sprite.setScale(-1.f, 1.f);
        if (GameManager::isCaseFree({currentPositionIndexes.x - 1, currentPositionIndexes.y})) {
            currentPositionIndexes = { currentPositionIndexes.x - 1, currentPositionIndexes.y };
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        isTravelling = true;
        animation.y = Direction::Side;
        sprite.setScale(1.f, 1.f);
        if (GameManager::isCaseFree({currentPositionIndexes.x + 1, currentPositionIndexes.y})) {
            currentPositionIndexes = { currentPositionIndexes.x + 1, currentPositionIndexes.y };
        }
    }
    sprite.setPosition(GameManager::translatePositionIndexes(currentPositionIndexes.x, currentPositionIndexes.y));
}

void Player::playAnimation(const sf::Time deltaTime) {
    timeSinceLastUpdate += deltaTime;
    if (timeSinceLastUpdate > animationTimePerFrame) {
        timeSinceLastUpdate -= animationTimePerFrame;
        if (!isTravelling) {
            animation = {6, Direction::Down};
        }
        else {
            animation.x++;
            if (animation.x > 2) {
                animation.x = 0;
            }
        }
        sprite.setTextureRect(sf::IntRect({animation.x * SPRITE_SIZE.x, animation.y * SPRITE_SIZE.y},
                                          {SPRITE_SIZE.x, SPRITE_SIZE.y}));
    }
}