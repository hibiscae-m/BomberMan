//
// Created by Marius on 16/08/2023.
//

#include "Player.h"
#include "ResourcesManager.h"
#include "GameManager.h"

Player::Player(int indexPositionX, int indexPositionY,
               sf::Keyboard::Key upButton,
               sf::Keyboard::Key downButton,
               sf::Keyboard::Key leftButton,
               sf::Keyboard::Key rightButton,
               sf::Keyboard::Key bombButton) :
               upButton(upButton), downButton(downButton), leftButton(leftButton), rightButton(rightButton), bombButton(bombButton)
{
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
    if (life > 0) {
        if (!isTravelling) {
            move();
        } else {
            travelling += deltaTime;
            if (travelling >= travelTime) {
                isTravelling = false;
                travelling = sf::Time::Zero;
            }
        }
        playAnimation(deltaTime);

        lastBombPlaced += deltaTime;
        if (lastBombPlaced >= bombCooldown) {
            if (sf::Keyboard::isKeyPressed(bombButton)) {
                GameManager::placeBomb(currentPositionIndexes.x, currentPositionIndexes.y);
                lastBombPlaced = sf::Time::Zero;
            }
        }
    }
}

void Player::move() {
    if (sf::Keyboard::isKeyPressed(upButton)) {
        isTravelling = true;
        animation.y = Direction::Up;
        if (GameManager::isCaseFree({currentPositionIndexes.x, currentPositionIndexes.y - 1})) {
            currentPositionIndexes = { currentPositionIndexes.x, currentPositionIndexes.y - 1 };
        }
    }
    else if (sf::Keyboard::isKeyPressed(downButton)) {
        isTravelling = true;
        animation.y = Direction::Down;
        if (GameManager::isCaseFree({currentPositionIndexes.x, currentPositionIndexes.y + 1})) {
            currentPositionIndexes = { currentPositionIndexes.x, currentPositionIndexes.y + 1 };
        }
    }
    else if (sf::Keyboard::isKeyPressed(leftButton)) {
        isTravelling = true;
        animation.y = Direction::Side;
        sprite.setScale(-1.f, 1.f);
        if (GameManager::isCaseFree({currentPositionIndexes.x - 1, currentPositionIndexes.y})) {
            currentPositionIndexes = { currentPositionIndexes.x - 1, currentPositionIndexes.y };
        }
    }
    else if (sf::Keyboard::isKeyPressed(rightButton)) {
        isTravelling = true;
        animation.y = Direction::Side;
        sprite.setScale(1.f, 1.f);
        if (GameManager::isCaseFree({currentPositionIndexes.x + 1, currentPositionIndexes.y})) {
            currentPositionIndexes = { currentPositionIndexes.x + 1, currentPositionIndexes.y };
        }
    }
    sprite.setPosition(GameManager::translatePositionIndexes(currentPositionIndexes.x, currentPositionIndexes.y));
}

sf::Vector2i Player::getCurrentPositionIndexes() {
    return currentPositionIndexes;
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

void Player::damaged() {
    life--;
    sprite.setTextureRect(sf::IntRect({0, 4 * SPRITE_SIZE.y},
                                      {SPRITE_SIZE.x, SPRITE_SIZE.y}));
}
