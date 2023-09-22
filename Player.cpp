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
    move(deltaTime);
    playAnimation(deltaTime);
}

void Player::move(const sf::Time deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        animation.y = Direction::Up;
        if (GameManager::isNextCaseFree(currentPositionIndexes, GameManager::DIRECTIONS::Up)) {
            currentPositionIndexes = { currentPositionIndexes.x, currentPositionIndexes.y - 1 };
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        animation.y = Direction::Down;
        if (GameManager::isNextCaseFree(currentPositionIndexes, GameManager::DIRECTIONS::Down)) {
            currentPositionIndexes = { currentPositionIndexes.x, currentPositionIndexes.y + 1 };
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        animation.y = Direction::Side;
        sprite.setScale(-1.f, 1.f);
        if (GameManager::isNextCaseFree(currentPositionIndexes, GameManager::DIRECTIONS::Left)) {
            currentPositionIndexes = { currentPositionIndexes.x - 1, currentPositionIndexes.y };
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        animation.y = Direction::Side;
        sprite.setScale(1.f, 1.f);
        if (GameManager::isNextCaseFree(currentPositionIndexes, GameManager::DIRECTIONS::Right)) {
            currentPositionIndexes = { currentPositionIndexes.x + 1, currentPositionIndexes.y };
        }
    }
    sprite.setPosition(GameManager::translatePositionIndexes(currentPositionIndexes.x, currentPositionIndexes.y));
}

void Player::playAnimation(const sf::Time deltaTime) {
    timeSinceLastUpdate += deltaTime;
    if (timeSinceLastUpdate > animationTimePerFrame) {
        timeSinceLastUpdate -= animationTimePerFrame;
        if (isIdle) {
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